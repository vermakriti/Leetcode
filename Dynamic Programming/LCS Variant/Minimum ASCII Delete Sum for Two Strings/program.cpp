/*

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

*/

// TC-O(N*N) SC-O(N*N)
class Solution {
public:
    int dp[1005][1005];
    int solve(int i,int j,string &s1,string &s2){
        if(i>=s1.size() || j>=s2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans;
        if(s1[i]==s2[j]){
            int ascii=int(s1[i]);
            ans=ascii+solve(i+1,j+1,s1,s2);
        }
        else
            ans=max(solve(i+1,j,s1,s2),solve(i,j+1,s1,s2));
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof dp);
        int ascii=0;
        for(auto it:s1)
            ascii+=it;
        for(auto it:s2)
            ascii+=it;
        return ascii - 2*solve(0,0,s1,s2);
    }
};