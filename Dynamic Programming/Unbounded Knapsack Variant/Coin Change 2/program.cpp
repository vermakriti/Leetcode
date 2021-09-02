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