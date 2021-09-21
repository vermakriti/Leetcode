/*
1. You are given a string str.
2. Complete the body of getSS function - without changing signature - to calculate all subsequences of str.
Use sample input and output to take idea about subsequences.

*/

#include <bits/stdc++.h>
using namespace std;

void solve(int i,string s,string str,vector<string>&ans){
    ans.push_back(str);
    if(i>=s.size())
        return;
    for(int j=i;j<s.size();j++){
        str.push_back(s[j]);
        solve(j+1,s,str,ans);
        str.pop_back();
    }    
}
vector<string> gss(string s){
    vector<string> ans;
    string str="";
    solve(0,s,str,ans);
    return ans;    
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}