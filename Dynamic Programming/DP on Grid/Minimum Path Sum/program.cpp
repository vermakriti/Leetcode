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