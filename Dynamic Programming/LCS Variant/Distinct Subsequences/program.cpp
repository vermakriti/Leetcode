/*

Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.


Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit

Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag

*/

class Solution {
public:
    int dp[1005][1005];
    int solve(int i,int j,string &s,string &t){
        if(j==t.size())
            return 1;
        if(i==s.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        if(s[i]==t[j])
            ans=solve(i+1,j+1,s,t)+solve(i+1,j,s,t);
        else ans=solve(i+1,j,s,t);
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,s,t);
    }
};