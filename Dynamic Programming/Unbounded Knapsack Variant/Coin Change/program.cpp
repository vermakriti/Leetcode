/*

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

*/

class Solution {
public:
    int dp[15][10005];
    int solve(int i,int amount,vector<int>& coins){
        if(amount==0)
            return 0;
        if(i>=coins.size() || amount<0)
            return 1e9;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int ans=0;
        if(coins[i]<=amount)
           ans=min(1+solve(i,amount-coins[i],coins),solve(i+1,amount,coins));
        else ans=solve(i+1,amount,coins);
        return dp[i][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        int ans=solve(0,amount,coins);
        if(ans==1e9)
            return -1;
        return ans;
    }
};