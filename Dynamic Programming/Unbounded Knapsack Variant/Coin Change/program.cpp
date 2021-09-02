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