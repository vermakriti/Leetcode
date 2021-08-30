class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode*construct(vector<int>& in, vector<int>& po,int start,int end,int &index){
        if(start>end)
            return NULL;
        TreeNode*node=new TreeNode(po[index--]);
        if(start==end)
            return node;
        node->right=construct(in,po,mp[node->val]+1,end,index);
        node->left=construct(in,po,start,mp[node->val]-1,index);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        
        int n=inorder.size(),index=n-1;
        return construct(inorder,postorder,0,n-1,index);
    }
};