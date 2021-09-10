class Solution {
public:
    void solve(TreeNode*root,vector<int> &s){
        if(!root)
            return;
        if(!root->left && !root->right){
            s.push_back(root->val);
            return;
        }
        solve(root->left,s);
        solve(root->right,s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        if(!root1 && !root2)return false;
        vector<int> s1,s2;
        solve(root1,s1);
        solve(root2,s2);
        if(s1==s2)
            return true;
        return false;
    }
};