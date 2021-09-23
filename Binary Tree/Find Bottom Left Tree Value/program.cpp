/*

Given the root of a binary tree, return the leftmost value in the last row of the tree.

Example 1:
Input: root = [2,1,3]
Output: 1

Example 2:
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7

*/

//TC-O(N) SC-O(N)
class Solution {
public:
    void solve(TreeNode*root,int level,int &maxLevel,int& bottomLeft){
        if(!root)
            return;
        if(level>maxLevel){
            bottomLeft=root->val;
            maxLevel=level;
        }
        solve(root->left,level+1,maxLevel,bottomLeft);
        solve(root->right,level+1,maxLevel,bottomLeft);
    }
    int findBottomLeftValue(TreeNode* root) {
        int level=1,maxLevel=1,bottomLeft=root->val;
        solve(root,level,maxLevel,bottomLeft);
        return bottomLeft;
    }
};