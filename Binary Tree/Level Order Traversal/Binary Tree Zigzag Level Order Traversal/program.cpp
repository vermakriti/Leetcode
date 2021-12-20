/*

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

*/

// TC-O(N) SC-O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        
        queue<TreeNode*> q;
        bool flag=true;
        
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> a;
            while(size--){
                TreeNode*curr=q.front();
                q.pop();
                a.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(flag){
                ans.push_back(a);
                flag=false;
            }
            else{
                reverse(a.begin(),a.end());
                ans.push_back(a);
                flag=true;
            }
        }
        return ans;
        
    }
};


// TC-O(N) SC-O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root)return ans;
        
        queue<TreeNode*> q;
        bool leftToRight=true;
        q.push(root);
        
        while(!q.empty()){

            int size=q.size();
            vector<int> a(size);
            
            for(int i=0;i<size;i++){
                TreeNode*curr=q.front();
                q.pop();
                
                int j=(leftToRight) ? i : size-1 -i;
                a[j]=curr->val;
                    
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            leftToRight=!leftToRight;
            ans.push_back(a);
        }
        return ans; 
    }
};