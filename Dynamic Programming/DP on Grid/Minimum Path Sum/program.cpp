/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

*/

class Solution {
public:
    int dp[205][205];
    int solve(int i,int j,vector<vector<int>>& grid){
        
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        
        if(i>=grid.size() || j>=grid[0].size())
            return 1e9;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=min(solve(i+1,j,grid)+grid[i][j],solve(i,j+1,grid)+grid[i][j]);
        return dp[i][j]=ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,grid);
    }
};