/*

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:

Input: triangle = [[-10]]
Output: -10

*/

class Solution {
public:
    int dp[1005][1005];
    int solve(int i,int j,vector<vector<int>>& grid){
        
        if(i>=grid.size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=min(solve(i+1,j,grid)+grid[i][j],solve(i+1,j+1,grid)+grid[i][j]);
        return dp[i][j]=ans;
    }
    int minimumTotal(vector<vector<int>>& grid) {
    
        memset(dp,-1,sizeof dp);
        return solve(0,grid[0].size()/2,grid);
    }
};