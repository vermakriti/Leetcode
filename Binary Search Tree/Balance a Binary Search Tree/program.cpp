/*

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.


Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:

Input: root = [2,1,3]
Output: [2,1,3]

*/

class Solution {
public:
    void inorder(TreeNode*root,vector<int>&arr){
        if(!root)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* builtTree(int start,int end,vector<int>&arr){
        if(start>end)
            return nullptr;
        int mid = start+(end-start)/2;
        TreeNode*node= new TreeNode(arr[mid]);
        if(start==end)
            return node;
        node->left=builtTree(start,mid-1,arr);
        node->right=builtTree(mid+1,end,arr);
        
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        int n=arr.size();
        return builtTree(0,n-1,arr);
    }
};