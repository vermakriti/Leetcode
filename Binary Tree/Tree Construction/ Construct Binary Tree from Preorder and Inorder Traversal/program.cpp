class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode*construct(vector<int>& pre, vector<int>& in,int start,int end,int &index){
        
        if(start>end)
            return NULL;
        TreeNode*node=new TreeNode(pre[index++]);
        if(start==end)
            return node;
        node->left=construct(pre,in,start,mp[node->val]-1,index);
        node->right=construct(pre,in,mp[node->val]+1,end,index);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        int index=0,n=inorder.size();
        return construct(preorder,inorder,0,n-1,index);
    }
};