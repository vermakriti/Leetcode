class Solution {
public:
    TreeNode*solve(vector<int> &v,int start,int end){
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode*node=new TreeNode(v[mid]);
        if(start==end)return node;
        node->left=solve(v,start,mid-1);
        node->right=solve(v,mid+1,end);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        TreeNode*root=solve(nums,0,n-1);
        return root;
    }
};