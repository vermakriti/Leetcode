vector<bool> visited;
stack<int> st;
void dfs(int i,vector<int> adj[]){
    
    visited[i]=true;
    for(int j:adj[i]){
        if(!visited[j])
            dfs(j,adj);
    }
    st.push(i);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    vector<int> v;
    visited.assign(V,false);
    for(int i=0;i<V;i++)
        if(!visited[i])
            dfs(i,adj);
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
    return v;
}
