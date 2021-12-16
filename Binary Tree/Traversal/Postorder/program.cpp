/***Recursive***/
class Solution {
public:
    void postorder(TreeNode *root,vector<int> &ans){
        
        if(!root)return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root){
        
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};

/*
	Iterative using 2 stacks
	
	1. Push root to first stack.
	2. Loop while first stack is not empty
	   2.1 Pop a node from first stack and push it to second stack
	   2.2 Push left and right children of the popped node to first stack
	3. Print contents of second stack    
	
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(!root)return ans;
        
        stack<TreeNode*> s1,s2;
        s1.push(root);
        
        while(!s1.empty()){
            
            TreeNode*curr=s1.top();
            s1.pop();
            s2.push(curr);
            
            if(curr->left)
                s1.push(curr->left);
            if(curr->right)
                s1.push(curr->right);
        }
        while(!s2.empty()){
            TreeNode*curr=s2.top();
            ans.push_back(curr->val);
            s2.pop();
        }
        return ans;
    }
};

/* Iterative using one stack */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(!root)return ans;
        
        TreeNode*curr=root,*temp;
        stack<TreeNode*> s;
        s1.push(root);
        
        while(curr || !s.empty()){
            
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                temp=s.top()->right;
                if(temp==nullptr){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && temp==s.top()->right){
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else curr=temp;
            }

        }
        return ans;
    }
};