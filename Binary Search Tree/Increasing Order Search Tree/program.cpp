class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
    
        if(!root)return root;
        TreeNode*prev=nullptr,*curr=root;
        stack<TreeNode*> st;
        
        while(curr || !st.empty()){
            
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            if(prev==nullptr){
                root=curr;
            }    
            else{
                prev->right=curr;
            }
            curr->left=nullptr;
            prev=curr;
            curr=curr->right;
        }
        return root;
    }
};