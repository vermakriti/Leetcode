// Right Side View 

/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:

Input: root = [1,null,3]
Output: [1,3]

Example 3:

Input: root = []
Output: []

*/


// TC-O(N) SC-O(N) iterative solution
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int i=1,size=q.size();
            while(i<=size){
                TreeNode*curr=q.front();
                q.pop();
                if(i==size)
                    ans.push_back(curr->val);
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                i++;
            }     
        }
        return ans;
    }
};
// TC-O(N) SC-O(N) recursive solution
class Solution {
public:
    void solve(TreeNode*root,vector<int>&ans,int level,int &max_level){
        if(!root)
            return;
        if(level>max_level)
            ans.push_back(root->val);
        max_level=max(level,max_level);
        
        solve(root->right,ans,level+1,max_level);
        solve(root->left,ans,level+1,max_level);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int max_level=0;
        solve(root,ans,1,max_level);
        return ans;
    }
};







/********Left Side View**********/

// TC-O(N) SC-O(N) recursive solution
void solve(TreeNode*root,vector<int>&ans,int level,int &max_level){
    if(!root)
        return;
    if(level>max_level)
        ans.push_back(root->data);
    max_level=max(level,max_level);
    
    solve(root->left,ans,level+1,max_level);
    solve(root->right,ans,level+1,max_level);
}
vector<int> leftView(TreeNode *root)
{
    vector<int> ans;
    int max_level=0;
    solve(root,ans,1,max_level);
    return ans;
}

// TC-O(N) SC-O(N) iterative solution
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int i=1,size=q.size();
            while(i<=size){
                TreeNode*curr=q.front();
                q.pop();
                if(i==1)
                    ans.push_back(curr->val);
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                i++;
            }     
        }
        return ans;
    }
};