// adjacency matrix 

#include<bits/stdc++.h>
using namespace std;

int main(){
	int v,e,u,v;
	cin >> v >> e;

	// adjacency matrix
	int adj[v+1][v+1];

	//take edge as input
	for(int i=0;i<e;i++){
		cin>>u>>v;
		adj[u][v]=1;
		adj[v][u]=1;
	}
	return 0;
}

//adjacency list

#include<bits/stdc++.h>
using namespace std;

int main(){
	int v,e,u,v;
	cin >> v >> e;

	// adjacency list
	vector<int> adj[v+1];

	//take edge as input
	for(int i=0;i<e;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	return 0;
}

// weighted graph

#include<bits/stdc++.h>
using namespace std;

int main(){
	int v,e,u,v,w;
	cin >> v >> e;

	// adjacency list
	vector<pair<int,int>> adj[v+1];

	//take edge as input
	for(int i=0;i<e;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	return 0;
}