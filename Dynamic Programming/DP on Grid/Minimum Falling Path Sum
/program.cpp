class Solution {
public:
    int dp[1050][105];
    int solve(int i,int j,vector<vector<int>>& matrix){
        
        if(i>=matrix.size() || j>=matrix[0].size() || j<0)
            return 1e9;
        
        if(i==matrix.size()-1)
            return matrix[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=matrix[i][j]+min({solve(i+1,j-1,matrix),solve(i+1,j,matrix),solve(i+1,j+1,matrix)});
        
        return dp[i][j]=ans;
       
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof dp);
        int ans=INT_MAX;
        for(int j=0;j<matrix[0].size();j++)
            ans=min(ans,solve(0,j,matrix));
        return ans;
    }
};