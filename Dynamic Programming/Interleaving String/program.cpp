/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 
Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true

*/

// TC-O(N*N) SC-O(N*N)
class Solution {
public:
    int dp[105][105];
    int solve(int i,int j,int k,string& s1,string& s2,string& s3){
        if(k==s3.size())
             return (i==s1.size() && j==s2.size());
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            if(s3[k]==s1[i])
                ans=solve(i+1,j,k+1,s1,s2,s3) || solve(i,j+1,k+1,s1,s2,s3);
        }
        else{
            if(s1[i]==s3[k])
                ans=solve(i+1,j,k+1,s1,s2,s3);
            if(s2[j]==s3[k])
                ans=solve(i,j+1,k+1,s1,s2,s3);
        }    
        return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        memset(dp,-1,sizeof dp);
        return solve(0,0,0,s1,s2,s3);
    }
};