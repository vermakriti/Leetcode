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
    int deepestLeavesSum(TreeNode* root) {
        
        if(!root)
            return 0;
        int ans=0;
        int height=maxHeight(root);
        solve(root,height,1,ans);
        return ans;
        
    }
};