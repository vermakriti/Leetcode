class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    queue<int> q;
	    int count=0;
	    
	    for(int i=0;i<V;i++){
	         for(auto j:adj[i]){
	             indegree[j]++;
	         }
	    }
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        count++;
	        int node=q.front();
	        q.pop();
	        for(auto i:adj[node]){
	            indegree[i]--;
	            if(indegree[i]==0)
	                q.push(i);
	        }
	    }
	    if(count==V)
	    	return false;
	    return true;
	}
};
