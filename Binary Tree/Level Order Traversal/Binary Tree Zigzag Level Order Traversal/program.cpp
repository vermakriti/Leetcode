class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        
        queue<TreeNode*> q;
        bool flag=true;
        
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
            if(flag){
                ans.push_back(a);
                flag=false;
            }
            else{
                reverse(a.begin(),a.end());
                ans.push_back(a);
                flag=true;
            }
        }
        return ans;
        
    }
};