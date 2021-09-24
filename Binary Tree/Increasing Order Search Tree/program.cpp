/*

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

Example 1:

Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

Example 2:

Input: root = [5,1,7]
Output: [1,null,5,null,7]

*/

// iterative inorder TC-O(N) SC-O(N)
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
                curr->left=nullptr;
                prev=curr;
            }    
            else{
                prev->right=curr;
                curr->left=nullptr;
                prev=curr;
            }
            curr=curr->right;
        }
        return root;
    }
};

//recursive inorder TC-O(N) SC-O(N)
class Solution {
public:
    TreeNode*prev=nullptr,*head=nullptr;
    void inorder(TreeNode*root){
        if(!root)
            return;
        inorder(root->left);
        if(prev==nullptr)
            head=root;
        else
            prev->right=root;
        prev=root;
        root->left=nullptr;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
       
        inorder(root);
        return head;
        
    }
};