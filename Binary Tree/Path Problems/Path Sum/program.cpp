/*

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true

Example 2:

Input: root = [1,2,3], targetSum = 5
Output: false

*/

//TC-O(N) SC-O(N)
class Solution {
public:
   
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        if(!root->left && !root->right){
            targetSum-=root->val;
            if(targetSum==0)
                return true;
            return false;
        }
        targetSum-=root->val;
        if(hasPathSum(root->left,targetSum))
            return true;
        if(hasPathSum(root->right,targetSum))
            return true;
        return false;
        
    }
};