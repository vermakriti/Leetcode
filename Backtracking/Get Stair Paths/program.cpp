/*

1. You are given a number n representing number of stairs in a staircase.
2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
3. Complete the body of getStairPaths function - without changing signature - to get the list of all paths that can be used to climb the staircase up.
Use sample input and output to take idea about output.

Sample Input
3

Sample Output
[111, 12, 21, 3]

*/

#include<bits/stdc++.h>
using namespace std;

void solve(int i,int n,vector<string>&ans,int step[],string s){
    
    if(i==n){
        ans.push_back(s);
        return;
    }
    if(i>n)
        return;
    for(int j=0;j<3;j++){
        char ch= step[j]+'0';
        s.push_back(ch);
        solve(i+step[j],n,ans,step,s);
        s.pop_back();
    }    
}

int main(){
    
    int n;
    cin>>n;
    vector<string> ans;
    string s;
    int step[]={1,2,3};
    solve(0,n,ans,step,s);
    int ss=ans.size();
    cout<<"[";
    for(int i=0;i<ss-1;i++)
        cout<<ans[i]<<", ";
        
    cout<<ans[ss-1]<<"]";    
    return 0;    
}