/*

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1

*/

// TC-O(N) SC-O(N)
class Solution {
public:
    void inorder(TreeNode*root,int &prevValue,int &minDist){
        if(!root)
            return; 
        inorder(root->left,prevValue,minDist);
        minDist = min(minDist,abs(prevValue-root->val));
        prevValue=root->val;
        inorder(root->right,prevValue,minDist);
    }
    int minDiffInBST(TreeNode* root){
        if(!root) return 0;
        int prevValue = INT_MAX,minDist=INT_MAX;
        inorder(root,prevValue,minDist);
        return minDist;
    }
};