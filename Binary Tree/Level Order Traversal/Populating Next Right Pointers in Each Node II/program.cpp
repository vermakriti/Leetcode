class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root)return root;
        Node*prev=NULL;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size=q.size();
            int i=1;
            while(i<=size){
                Node*curr=q.front();
                q.pop();
                if(i==1){
                    prev=curr;
                }
                else{
                    prev->next=curr;
                    prev=curr;
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                i++;
            }
            
        }
        return root;
    }
};