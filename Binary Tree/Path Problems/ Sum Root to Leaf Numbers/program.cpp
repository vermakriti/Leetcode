/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

Example 1:

Input: root = [1,2,3]
Output: 25

Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

*/

// TC-O(N) SC-O(N)
class Solution {
public:

    void solve(TreeNode*root,string s,int &ans){
        if(!root)return;
        if(!root->left && !root->right){
            s.push_back(root->val+'0');
            ans+=stoi(s);
            return;
        }
        s.push_back(root->val+'0');
        solve(root->left,s,ans);
        solve(root->right,s,ans);
    }
    int sumNumbers(TreeNode* root) {
       
        int ans=0;
        string s;
        solve(root,s,ans);
        return ans;
    }
};