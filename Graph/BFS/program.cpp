class Solution{

	public:
		vector<int> bfsOfGraph(int V,vector<int>adj[]){

			vector<int> bfs;
			vector<int>visited(V+1,0);

			for(int i=1;i<=V;i++){
				if(!visited[i]){
					queue<int> q;
					q.push(i);
					visited[i]=1;
					while(!q.empty()){

						int node=q.front();
						q.pop();
						bfs.push_back(node);

						for(int it:adj[node]){
							if(!visited[it]){
								visited[it]=1;
								q.push(it);
							}
						}
					}
				}	

			}
			return bfs;
		}
};