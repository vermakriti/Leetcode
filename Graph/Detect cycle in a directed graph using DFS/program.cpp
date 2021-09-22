class Solution
{
    public:
    bool checkForCycle(int i,vector<int>adj[],vector<bool> &visited,vector<bool> &recur){
        
        if(recur[i])
            return true;
        if(visited[i])
            return false;
        recur[i]=true;
        visited[i]=true;
        for(auto it :adj[i]){
            
            if(checkForCycle(it,adj,visited,recur))
                return true;
        
        }
        recur[i]=false;
        return false;
    }
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<bool> visited(V,false),recur(V,false);
	   	for(int i=0;i<V;i++){
	   	    if(!visited[i]){
	   	        if(checkForCycle(i,adj,visited,recur))
	   	            return true;
	   	    }
	   	}
	   	return false;
	}
};