class Solution {
public:
    void solve(TreeNode*root,string s,string &ans){
        if(!root)
            return;
        if(!root->left && !root->right){
            s+=('a'+ root->val);
            string t=s;
            reverse(t.begin(),t.end());
            if(ans==""){
                ans=t;
                return;
            }
            if(ans>t)
                ans=t;
            return;
        }
       
        s+= ('a'+root->val);
        solve(root->left,s,ans);
        solve(root->right,s,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="",s="";
        solve(root,s,ans);
        return ans;
    }
};