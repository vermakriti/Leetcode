/*

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0

*/

// TC-O(2^N) SC-O(N)
class Solution{
    public:
    int solve(int i,int n,int W, int wt[], int val[]){
        
        if(i>=n || W<=0)
            return 0;
        int ans;    
        if(wt[i]<=W)
            ans=max(solve(i+1,n,W-wt[i],wt,val)+val[i],solve(i+1,n,W,wt,val));
        else ans = solve(i+1,n,W,wt,val);
        
        return ans;
    }
    int knapSack(int W, int wt[], int val[], int n){ 
        return solve(0,n,W,wt,val);
    }
};


// TC-O(N*W) SC-O(N*W)
// Top-Down DP
class Solution{
    public:
    int dp[1005][1005];
    int solve(int i,int n,int W, int wt[], int val[]){
        
        if(i>=n || W<=0)
            return 0;
        if(dp[i][W]!=-1)
            return dp[i][W];
        int ans;    
        if(wt[i]<=W)
            ans=max(solve(i+1,n,W-wt[i],wt,val)+val[i],solve(i+1,n,W,wt,val));
        else ans = solve(i+1,n,W,wt,val);
        
        return dp[i][W]=ans;
    }
    int knapSack(int W, int wt[], int val[], int n){ 
        memset(dp,-1,sizeof dp);
        return solve(0,n,W,wt,val);
    }
};


