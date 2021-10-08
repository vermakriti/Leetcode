/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

*/

class Solution {
public:
    int dp[1005][1005];
    int lcs(int i,int j,string &s,string &a){
        
        if(i>=s.size() || j>=a.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans;
        if(s[i]==a[j])
            ans=1+lcs(i+1,j+1,s,a);
        else ans=max(lcs(i,j+1,s,a),lcs(i+1,j,s,a));
        
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof dp);
        string a="";
        for(int i=s.size()-1;i>=0;i--)
            a+=s[i];
        
        int len = lcs(0,0,s,a);
        return len;
    }
};