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