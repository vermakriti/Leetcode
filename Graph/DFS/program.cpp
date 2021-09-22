class Solution{

	public:
		void dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&storeDfs){

			visited[node]=1;
			storeDfs.push_back(node);

			for(auto it:adj[node]){
				if(!visited[it])
					dfs(it,adj,visited,storeDfs);
			}

		}
		vector<int> dfsOfGraph(int V,vector<int>adj[]){

			vector<int> storeDfs;
			vector<int>visited(V+1,0);

			for(int i=1;i<=V;i++){
				if(!visited[i]){
					dfs(i,adj,visited,storeDfs);
				}	

			}
			return storeDfs;
		}
};