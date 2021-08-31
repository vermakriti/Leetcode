class Solution {
public:
    void solve(TreeNode*root,vector<int> temp,vector<vector<int>>&ans,int targetSum){
        if(!root)return;
        if(!root->left && !root->right){
            targetSum-=root->val;
            if(targetSum==0){
                temp.push_back(root->val);
                ans.push_back(temp);
            }
            return;
        }
        targetSum-=root->val;
        temp.push_back(root->val);
        
        solve(root->left,temp,ans,targetSum);
        solve(root->right,temp,ans,targetSum);
       
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,temp,ans,targetSum);
        return ans;
    }
};