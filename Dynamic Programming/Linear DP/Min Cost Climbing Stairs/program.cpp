class Solution {
public:
    int dp[1005];
    int solve(int i,vector<int>& cost){
        if(i>=cost.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=min(cost[i]+solve(i+1,cost),cost[i]+solve(i+2,cost));
        return dp[i]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        int ans1=solve(0,cost);
        memset(dp,-1,sizeof dp);
        int ans2=solve(1,cost);
        
        return min(ans1,ans2);
    }
};