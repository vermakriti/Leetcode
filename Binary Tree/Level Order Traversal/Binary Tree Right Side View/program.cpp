class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int i=1,size=q.size();
            while(i<=size){
                TreeNode*curr=q.front();
                q.pop();
                if(i==size)
                    ans.push_back(curr->val);
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                i++;
            }     
        }
        return ans;
    }
};