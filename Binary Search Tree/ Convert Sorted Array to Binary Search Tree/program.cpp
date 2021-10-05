/*

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.

*/

class Solution {
public:
    TreeNode*solve(vector<int> &v,int start,int end){
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode*node=new TreeNode(v[mid]);
        if(start==end)return node;
        node->left=solve(v,start,mid-1);
        node->right=solve(v,mid+1,end);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        TreeNode*root=solve(nums,0,n-1);
        return root;
    }
};