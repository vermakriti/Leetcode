/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// using bfs traversal
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(!root)
            return 0;
        int sum=0;
        queue<pair<TreeNode*,char>>q;
        q.push({root,'r'});
        while(!q.empty()){
            
            int size=q.size();
            int i=1;
            while(i<=size){
                TreeNode*curr=q.front().first;
                char ch=q.front().second;
                q.pop();
                
                if(ch=='l' && !curr->left && !curr->right)
                    sum+=curr->val;
                if(curr->left)
                    q.push({curr->left,'l'});
                if(curr->right)
                    q.push({curr->right,'r'});
                i++;
            }
        }
        return sum;
        
    }
};

// using dfs traversal 

class Solution {
public:
    void solve(TreeNode*root,char leave,int &sum){
        if(!root)
            return;
        if(leave=='l' && !root->left && !root->right){
            sum+=root->val;
            return;
        }
        solve(root->left,'l',sum);
        solve(root->right,'r',sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum=0;
        char leave;
        solve(root,leave,sum);
        return sum;
    }
};