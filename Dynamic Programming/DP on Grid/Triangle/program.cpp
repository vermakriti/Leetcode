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