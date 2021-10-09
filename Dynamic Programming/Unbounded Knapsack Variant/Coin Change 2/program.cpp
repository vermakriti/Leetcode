/*

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

*/

class Solution {
public:
    int dp[305][5005];
    int solve(int i,int amount,vector<int>& coins){
        
        if(amount==0)
            return 1;
        if(i>=coins.size() || amount<0)
            return 0;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int ans = solve(i,amount-coins[i],coins) + solve(i+1,amount,coins);
        return dp[i][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        return solve(0,amount,coins);
    }
};