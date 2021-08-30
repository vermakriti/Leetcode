
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==nullptr)return ans;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int ss = q.size();
            vector<int> a;
            
            while(ss--){
                
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
        return ans;
    }
};

