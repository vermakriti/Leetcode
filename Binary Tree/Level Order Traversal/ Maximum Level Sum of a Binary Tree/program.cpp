class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        int level=1,max_sum=INT_MIN,ans;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            while(size--){
                TreeNode*curr=q.front();
                q.pop();
                
                sum+=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(sum>max_sum){
                ans=level;
                max_sum=sum;
            }
            level++;
        }
        return ans;
    }
};