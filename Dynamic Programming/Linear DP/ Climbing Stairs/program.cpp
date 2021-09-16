/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:

1 <= n <= 45

*/

//brute force TC-O(2^N) SC-O(1)
class Solution {
public:
    int solve(int i,int n){
        if(i==n)
            return 1;
        if(i>n)
            return 0;
        return solve(i+1,n)+solve(i+2,n);
    }
    int climbStairs(int n) {
        return solve(0,n);
    }
};

//optimize Tc-O(N*N) SC-O(N*N)
class Solution {
public:
    int dp[50];
    int solve(int i,int n){
        if(i==n)
            return 1;
        if(i>n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=solve(i+1,n)+solve(i+2,n);
        return dp[i]=ans;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
        return solve(0,n);
    }
};
