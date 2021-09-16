/*
Company - Facebook,Amazon,Microsoft,Bloomberg

Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

Example 2:

Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]

*/

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<pair<TreeNode*,int>> q;
        map<int,vector<int>> hash;
        
        q.push({root,0});
        while(!q.empty()){
            TreeNode*curr=q.front().first;
            int dist = q.front().second;
            q.pop();
            
            hash[dist].push_back(curr->val);
            
            if(curr->left)
                q.push({curr->left,dist-1});
            if(curr->right)
                q.push({curr->right,dist+1});
        }
        
        for(auto ele:hash)
            ans.push_back(ele.second);
        return ans;
    }
};