/******Algorithm*****/
 
/*

maintain set of processed nodes and assign all nodes with distance value = INt_MAX 
except souce node

Repeat following 
1)- Pich min value vertex which is not already processed
2)- Include this selected  node in SET(processed set)
3)- Update all the adjacent node distance if(New distance < old distance)
	then update... else skip

*/


// TC-O(ElogV) SC-O(V)
class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int> processed(V,0),dist(V,INT_MAX);
        priority_queue<pair<int,int>> q;
        q.push({0,S});
        dist[S]=0;
        
        while(!q.empty()){
            int node=q.top().second;
            int distance = -1*q.top().first;
            q.pop();
            
            for(auto it:adj[node]){
                if(distance+it[1]<dist[it[0]] && processed[it[0]]==0){
                    dist[it[0]]=distance+it[1];
                    q.push({-1*dist[it[0]],it[0]});
                }
            }
            processed[node]=1;
        }
        return dist;
    }
};