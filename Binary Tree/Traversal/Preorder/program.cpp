/***Recursive***/
class Solution {
public:
    void preorder(TreeNode* root,vector<int> &ans){
        
        if(!root)return;
        v.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};

/* 
	Iterative

	1) Create an empty stack and push root node to stack. 
	2) Do the following while Stack is not empty. 
		a) Pop an item from the stack and print it. 
		b) Push right child of a popped item to stack 
		c) Push left child of a popped item to stack
*/


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
       	stack<Node*> st;
	    vector<int> ans;
	    st.push(root);
	    while(!st.empty()){
	        
	        Node*curr=st.top();
	        ans.push_back(curr->data);
	        st.pop();
	        
	        if(curr->right)
	            st.push(curr->right);
	        if(curr->left)
	            st.push(curr->left);
	    }
	    return ans;
       	
    }
};