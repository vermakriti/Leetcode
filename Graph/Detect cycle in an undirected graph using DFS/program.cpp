// TC- O(V+E) SC-O(V)
class Soltution{
  	public:
    bool dfs(int node,int parent,vector<int>adj[],vector<int>&visited){
        visited[node]=1;
        for(int it:adj[node]){
            if(!visited[it]){
                if(dfs(it,node,adj,visited))
                    return true;
            }
            else if(it!=parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited))
                    return true;
            }
        }
        return false;
    }
};