/*

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum underlined below:
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]

Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is underlined below:
[[-19,57],
 [-40,-5]]


 */

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