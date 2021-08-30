class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            vector<int> a;
            
            while(size--){
                Node*curr=q.front();
                q.pop();
                
                a.push_back(curr->val);
                for(int i=0;i<curr->children.size();i++){
                    if(curr->children[i])
                        q.push(curr->children[i]);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};