/*

Given the roots of two binary search trees, root1 and root2, return true if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.

Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false

*/

// TC-O(MlogN) SC-O(M)
class Solution {
public:
    TreeNode*search(TreeNode*root,int key){
        if(!root)
            return root;
        if(root->val==key)
            return root;
        if(key<root->val)
            return search(root->left,key);
        return search(root->right,key);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
        stack<TreeNode*> st;
        st.push(root1);
        while(!st.empty()){
            TreeNode*curr=st.top();
            st.pop();
            
            TreeNode*node=search(root2,target-curr->val);
            if(node) return true;
            
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
        }
        return false;
    }
};