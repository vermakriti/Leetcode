class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root)return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            int n=size;
            double sum=0;
            while(size--){
                TreeNode*curr=q.front();
                q.pop();
                
                sum+=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            double avg=sum/n;
            ans.push_back(avg);
        }
        return ans;
    }
};