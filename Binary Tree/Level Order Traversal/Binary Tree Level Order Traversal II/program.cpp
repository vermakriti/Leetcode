class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> a;
            while(size--){
                TreeNode*curr=q.front();
                q.pop();
                a.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back(a);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};