/*****Algorithm*****/

/*
1)- Initialize all distance values as INT_MAX except souce
2)- Repeat (No of nodes-1) times 
	if dist[u]+distance/cost between u and v <dist[v]
		then update dist[u]
	else skip
3)- Relax all vehicles once more if we find any new shortest distance value then we 
	have -ve edge weight cycle else we don't.

*/

// TC-O(V*E) SC-O(V)
class Solution{
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n,INT_MAX);
	    dist[0]=0;
	    
	    for(int i=0;i<n-1;i++){
	       	for(int j=0;j<edges.size();j++){
	            if(dist[edges[j][0]]!=INT_MAX){
    	            if(dist[edges[j][0]]+edges[j][2]<dist[edges[j][1]])
    	                dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
	            }         
	       	}
	    }
        for(int j=0;j<edges.size();j++){
            if(dist[edges[j][0]]!=INT_MAX){
                if(dist[edges[j][0]]+edges[j][2]<dist[edges[j][1]])
                    return 1;
            }        
                     
       }
       return 0;
	}
};