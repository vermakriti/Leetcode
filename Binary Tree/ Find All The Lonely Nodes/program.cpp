/*
n a binary tree, a lonely node is a node that is the only child of its parent node. The root of the tree is not lonely because it does not have a parent node.

Given the root of a binary tree, return an array containing the values of all lonely nodes in the tree. Return the list in any order.

Example 1:
Input: root = [1,2,3,null,4]
Output: [4]
Explanation: Light blue node is the only lonely node.
Node 1 is the root and is not lonely.
Nodes 2 and 3 have the same parent and are not lonely.

*/

class Solution {
public:
    void solve(TreeNode*root,vector<int>&ans){
        if(!root)
            return;
        if(!root->left && root->right)
            ans.push_back(root->right->val);
        if(root->left && !root->right)
            ans.push_back(root->left->val);
        solve(root->left,ans);
        solve(root->right,ans); 
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};