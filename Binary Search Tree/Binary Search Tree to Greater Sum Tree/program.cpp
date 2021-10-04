/*

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Example 2:

Input: root = [0,null,1]
Output: [1,null,1]

*/

// iterative TC-O(N) SC-O(N)
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        
        if(!root)
            return root;
        int sum=0,mod=1e9+7;
        stack<TreeNode*> st;
        TreeNode*curr=root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->right;
            }
            curr=st.top();
            st.pop();
            curr->val=(curr->val % mod + sum % mod)%mod;
            sum=curr->val;
            curr=curr->left;
          
        }
        return root;
    }
};

//recursive TC-O(N) SC-O(N)
class Solution {
public:
    void solve(TreeNode*root,int& sum){
        if(!root)
            return;
        solve(root->right,sum);
        root->val = root->val + sum;
        sum=root->val;
        solve(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        solve(root,sum);
        return root;
    }
};