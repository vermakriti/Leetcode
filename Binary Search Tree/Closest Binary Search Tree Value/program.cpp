/*

Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target.

Example 1:

Input: root = [4,2,5,1,3], target = 3.714286
Output: 4

Example 2:

Input: root = [1], target = 4.428571
Output: 1

*/

class Solution {
public:
    void solve(TreeNode*root,double target,double difference, int &ans){
        if(!root) return;
        double diff=abs(target-root->val);
        if(diff<difference){
            difference=diff;
            ans=root->val;
        }    
        if( target < root->val)
             solve(root->left,target,difference,ans);
        else 
             solve(root->right,target,difference,ans);
    }
    int closestValue(TreeNode* root, double target) {
        int ans=INT_MAX;
        solve(root,target,DBL_MAX,ans);
        return ans;
    }
};