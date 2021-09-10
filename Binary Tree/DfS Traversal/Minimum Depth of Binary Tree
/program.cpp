class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int left= root->left ? minDepth(root->left) : INT_MAX;
        int right = root->right ? minDepth(root->right) : INT_MAX;
        return min(left,right)+1;
    }
};