/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false

*/

//level order traversal
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(!p && !q)return true;
        if(!p && q)return false;
        if(p && !q)return false;
        
        queue<TreeNode*> q1,q2;
        q1.push(p);
        q2.push(q);
        
        while(!q1.empty() && !q2.empty()){
            
            TreeNode *curr1=q1.front();
            TreeNode *curr2=q2.front();
            
            q1.pop();
            q2.pop();
            
            if((!curr1->left && curr2->left) || (curr1->left && !curr2->left))
                return false;
            if((!curr1->right && curr2->right) || (curr1->right && !curr2->right))
                return false;
            
            if(curr1->val!=curr2->val)
                return false;
            
            if(curr1->left && curr2->left){
                q1.push(curr1->left);
                q2.push(curr2->left);
            }
          
            if(curr1->right && curr2->right){
                q1.push(curr1->right);
                q2.push(curr2->right);
            }
            
              
        }
        
        if(q1.empty() && q2.empty() )
            return true;
        return false;
        
    }
};

// DFS traversal
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q)
            return (p==q);
        return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};