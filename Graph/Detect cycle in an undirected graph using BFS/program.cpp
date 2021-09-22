class Solution{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                
                queue<pair<int,int>> q;
                q.push({i,-1});
                visited[i]=1;
                
                while(!q.empty()){
                    
                    int node=q.front().first;
                    int parent=q.front().second;
                    q.pop();
                    
                    for(int it:adj[node]){
                        if(!visited[it]){
                            visited[it]=1;
                            q.push({it,node});
                        }
                        else if(it!=parent)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
