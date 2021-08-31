class Solution {
public:

    void solve(TreeNode*root,string s,int &ans){
        if(!root)return;
        if(!root->left && !root->right){
            s.push_back(root->val+'0');
            ans+=stoi(s);
            return;
        }
        s.push_back(root->val+'0');
        solve(root->left,s,ans);
        solve(root->right,s,ans);
    }
    int sumNumbers(TreeNode* root) {
       
        int ans=0;
        string s;
        solve(root,s,ans);
        return ans;
    }
};