/*

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]

*/

class Solution {
public:
    void solve(TreeNode*root,string s,vector<string>&ans){
        if(!root)return;
        if(!root->left && !root->right){
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(root->val);
        s+="-";
        s+=">";
        solve(root->left,s,ans);
        solve(root->right,s,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root)return ans;
        
        string s="";
        solve(root,s,ans);
        return ans;
    }
};