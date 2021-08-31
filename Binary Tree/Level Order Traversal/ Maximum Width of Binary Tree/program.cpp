class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)return 0;
        
        unsigned long long max_width=0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,1});
        
        while(!q.empty()){
            int size=q.size();
            unsigned long long l,r;
            l=q.front().second;
            while(size--){
                TreeNode*curr=q.front().first;
                r=q.front().second;
                q.pop();
                 
                if(curr->left)
                    q.push({curr->left,2*r});
                if(curr->right)
                    q.push({curr->right,2*r+1});
            }
            max_width=max(max_width,r-l+1);
        }
        return max_width;
    }
};