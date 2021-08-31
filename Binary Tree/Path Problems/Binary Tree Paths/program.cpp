class Solution {
public:
    void solve(TreeNode*root,string s,vector<string>&ans){
        if(!root)return;
        if(!root->left && !root->right){
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(root->val);
        s+="-";
        s+=">";
        solve(root->left,s,ans);
        solve(root->right,s,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root)return ans;
        
        string s="";
        solve(root,s,ans);
        return ans;
    }
};