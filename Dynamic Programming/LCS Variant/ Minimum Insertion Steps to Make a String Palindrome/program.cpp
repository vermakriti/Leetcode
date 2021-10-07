/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.

Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

Example 4:

Input: s = "g"
Output: 0

Example 5:

Input: s = "no"
Output: 1

*/

// TC-O(N*N) SC-O(N*N)
class Solution {
public:
    int dp[505][505];
    int solve(int i,int j,string &s1,string &s2){
        if(i>=s1.size() || j>=s2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans;
        if(s1[i]==s2[j])
            ans=1+solve(i+1,j+1,s1,s2);
        else ans=max(solve(i,j+1,s1,s2),solve(i+1,j,s1,s2));
        return dp[i][j]=ans;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof dp);
        string s1=s;
        int n=s.size();
        reverse(s1.begin(),s1.end());
        int len=solve(0,0,s,s1);
        return (n-len);
    }
};