/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?



Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6


Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.

*/
// brute force TC-O(2^N) SC-O(1)
class Solution {
public:
    int solve(int i,int j,int m,int n){
        if(i==m-1 && j==n-1)
            return 1;
        if(i>=m || j>=n)
            return 0;
        return solve(i+1,j,m,n) + solve(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};

// optimize TC-O(N*N) SC-O(N*N)
class Solution {
public:
    int dp[105][105];
    int solve(int i,int j,int m,int n){
        if(i==m-1 && j==n-1)
            return 1;
        if(i>=m || j>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=solve(i+1,j,m,n) + solve(i,j+1,m,n);
        return dp[i][j]=ans;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,m,n);
    }
};
