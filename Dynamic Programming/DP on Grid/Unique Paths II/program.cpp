/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.



Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

*/

// brute force TC-O(2^N) SC-O(1)
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i>=grid.size() || j>=grid[0].size())
            return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            if(grid[i][j])
                return 0;
            return 1;
        }
        if(grid[i][j])
            return 0;
        return solve(i+1,j,grid) + solve(i,j+1,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solve(0,0,obstacleGrid);
    }
};

//optimize TC-O(N*N) SC-O(N*N)
class Solution {
public:
    int dp[105][105];
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i>=grid.size() || j>=grid[0].size())
            return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            if(grid[i][j])
                return 0;
            return 1;
        }
        if(grid[i][j])
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=solve(i+1,j,grid) + solve(i,j+1,grid);
        return dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,obstacleGrid);
    }
};
