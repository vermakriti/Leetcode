/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].

*/

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
        int ans2=solve(1,cost);
        
        return min(ans1,ans2);
    }
};