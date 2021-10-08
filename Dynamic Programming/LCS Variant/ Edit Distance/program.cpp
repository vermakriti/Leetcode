/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

*/

class Solution {
public:
    int dp[505][505];
    int solve(int i,int j,string s1,string s2){
        if(i==s1.size())
            return s2.size()-j;
        if(j==s2.size())
            return s1.size()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j])
            ans=solve(i+1,j+1,s1,s2);
        else ans = 1+min({solve(i+1,j,s1,s2),solve(i+1,j+1,s1,s2),solve(i,j+1,s1,s2)});
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,word1,word2);
    }
};