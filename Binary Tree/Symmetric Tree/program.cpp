/*

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

*/

// level order traversal TC-O(N) SC-O(N)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(!root)return true;
        if((root->left && !root->right) ||(!root->left && root->right))
            return false;
        queue<TreeNode*>q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            
            TreeNode*front1,*front2;
            front1=q1.front();
            q1.pop();
            front2=q2.front();
            q2.pop();
            
            if(!front1 && !front2)
                continue;
            if(!front1 && front2)
                return false;
            if(front1 && !front2)
                return false;    
            if(front1->val!=front2->val)
                return false;
            
            q1.push(front1->left);
            q1.push(front1->right);
            
            q2.push(front2->right);
            q2.push(front2->left);
            
            
        }
        if(q1.empty() && q2.empty())
            return true;
        return  false;
    }
};


// DFS TC-O(N) SC-O(N)
class Solution {
public:
    bool solve(TreeNode*root1,TreeNode*root2){
        if(root1==nullptr || root2==nullptr)
            return (root1==root2);
        return (root1->val==root2->val)
            && solve(root1->left,root2->right) 
            && solve(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return solve(root->left,root->right);
        
    }
};