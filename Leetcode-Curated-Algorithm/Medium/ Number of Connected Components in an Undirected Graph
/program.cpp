/*

Company - Amazon,Linkedin,Facebook,Microsoft

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

 

Example 1:

Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2

Example 2:

Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
 

Constraints:

1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.

*/

class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int> &visited){
        
        visited[node]=1;
        for(auto child:adj[node]){
            if(!visited[child])
                dfs(child,adj,visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> visited(n,0);
        vector<int> adj[n+1];
        int component=0;
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i,adj,visited);
                component++;
            }
        }
        return component;
    }
};

/*
	Space Complexity:
	visited - O(V)
	Building the adjacency list  - O(E) - we iterate over egdes 

	= O(V+E)

	Time Complexity : O(V+E)
*/	
