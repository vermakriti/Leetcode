/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

*/

class Solution {
public:
    void solve(int open,int close,int n,vector<string>&ans, string &s){
        
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            solve(open+1,close,n,ans,s);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            solve(open,close+1,n,ans,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        solve(0,0,n,ans,s);
        return ans;
    }
};