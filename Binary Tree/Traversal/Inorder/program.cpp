/*

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

*/

//Recursive approach

class Solution {
public:
    void inorder(TreeNode *root,vector<int> &ans){
        
        if(root==NULL)return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};

/*
    Iterative Approach

    1) Create an empty stack S.
    2) Initialize current node as root
    3) Push the current node to S and set current = current->left until current is NULL
    4) If current is NULL and stack is not empty then 
         a) Pop the top item from stack.
         b) Print the popped item, set current = popped_item->right 
         c) Go to step 3.
    5) If current is NULL and stack is empty then we are done.
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode*curr=root;
        stack<TreeNode*> st;
        vector<int> ans;
        
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans;
    }
};