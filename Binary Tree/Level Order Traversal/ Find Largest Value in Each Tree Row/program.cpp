class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            int mx_ele=INT_MIN;
            while(size--){
                TreeNode*curr=q.front();
                q.pop();
                
                mx_ele=max(mx_ele,curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back(mx_ele);
        }
        return ans;
    }
};