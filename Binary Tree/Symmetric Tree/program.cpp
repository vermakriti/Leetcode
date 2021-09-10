class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(!root)return true;
        if((root->left && !root->right) ||(!root->left && root->right))
            return false;
        queue<TreeNode*>q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            
            TreeNode*front1,*front2;
            front1=q1.front();
            q1.pop();
            front2=q2.front();
            q2.pop();
            
            if(!front1 && !front2)
                continue;
            if(!front1 && front2)
                return false;
            if(front1 && !front2)
                return false;    
            if(front1->val!=front2->val)
                return false;
            
            q1.push(front1->left);
            q1.push(front1->right);
            
            q2.push(front2->right);
            q2.push(front2->left);
            
            
        }
        if(q1.empty() && q2.empty())
            return true;
        return  false;
    }
};