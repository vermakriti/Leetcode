/*

Given the root of a binary tree, return the sum of values of its deepest leaves.
 
Example 1:

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19

*/

/*
    TC- O(N) + O(N) - finding the max height and sum of max height leaves 
    TC- O(2*N)
    TC- O(N)

    SC-O(2*N)
    SC-O(N)
*/

class Solution {
public:
    int maxHeight(TreeNode*root){
        if(!root)
            return 0;
        return max(maxHeight(root->left),maxHeight(root->right)) +1;
    }
    void solve(TreeNode*root,int height,int h, int &ans){
        if(!root)
            return;
        if(h==height && !root->left && !root->right){
            ans+=root->val;
            return;
        }
        solve(root->left,height,h+1,ans);
        solve(root->right,height,h+1,ans);
    }
    int deepestLeavesSum(TreeNode* root){
        if(!root)
            return 0;
        int ans=0;
        int height=maxHeight(root);
        solve(root,height,1,ans);
        return ans;
        
    }
};


// TC-O(N) SC-O(N)

class Solution {
public:
    void solve(TreeNode*root,int &depth,int currDepth,int &sum){
        if(!root)
            return;
        if(!root->left && !root->right){
            if(currDepth>depth){
                depth=currDepth;
                sum=root->val;
            }
            else if(depth==currDepth)
                sum+=root->val;
            return;
        }
        solve(root->left,depth,currDepth+1,sum);
        solve(root->right,depth,currDepth+1,sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth=0,sum=0;
        solve(root,depth,0,sum);
        return sum;
    }
};