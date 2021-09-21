/*

1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
3. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
Use sample input and output to take idea about output.

*/
#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

void solve(int sr, int sc, int dr, int dc,string s,vector<string>&ans){
    
    if(sr==dr && sc==dc){
        ans.push_back(s);
        return;
    }
    if(sr>dr || sc>dc)
        return;
        
    s.push_back('h');
    solve(sr,sc+1,dr,dc,s,ans);
    s.pop_back();
    
    s.push_back('v');
    solve(sr+1,sc,dr,dc,s,ans);
    s.pop_back();
    
}
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    vector<string>ans;
    string s;
    solve(sr,sc,dr,dc,s,ans);
    return ans;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}