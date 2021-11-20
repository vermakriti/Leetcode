/*

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

*/

class Solution {
public:
    int dp[65];
    int mod=1e9+7;
    int solve(int n,int k){
        if(n==0){
            if(k>=2)
                return 1;
            return 0;
        }
        if(dp[n]!=-1)
            return dp[n];
        long long ans=0;
        for(long long i=1;i<=n;i++)
            ans=max(ans,solve(n-i,k+1)*i);
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof dp);
        return solve(n,0);
    }
};