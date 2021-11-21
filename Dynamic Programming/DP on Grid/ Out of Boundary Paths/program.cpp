/*

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

Example 1:

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

*/

// TC-4^N SC-O(N)
class Solution {
public:
    int mod=1e9+7;
    int solve(int& m,int& n,int maxMove,int startRow,int startColumn,vector<int>& x,vector<int>& y){
        
        if(startRow>=m || startColumn>=n || startRow <0 || startColumn <0)
            return 1;
        if(maxMove==0)
            return 0;
        int ans=0;
        for(int k=0;k<4;k++){
            ans = (ans % mod + solve(m,n,maxMove-1,startRow+x[k],startColumn+y[k],x,y) % mod)%mod;
        }
        return ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<int>x{1,-1,0,0};
        vector<int>y{0,0,1,-1};
        return solve(m,n,maxMove,startRow,startColumn,x,y);
    }
};


// TC-O(m*n*maxMove) SC-O(m*n*maxMove)
class Solution {
public:
    int dp[60][60][60];
    int mod=1e9+7;
    int solve(int& m,int& n,int maxMove,int startRow,int startColumn,vector<int>& x,vector<int>& y){
        
        if(startRow>=m || startColumn>=n || startRow <0 || startColumn <0)
            return 1;
        if(maxMove==0)
            return 0;
        if(dp[startRow][startColumn][maxMove]!=-1)
            return dp[startRow][startColumn][maxMove];
        int ans=0;
        for(int k=0;k<4;k++){
            ans = (ans % mod + solve(m,n,maxMove-1,startRow+x[k],startColumn+y[k],x,y) % mod)%mod;
        }
        return dp[startRow][startColumn][maxMove] = ans;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof dp);
        vector<int>x{1,-1,0,0};
        vector<int>y{0,0,1,-1};
        return solve(m,n,maxMove,startRow,startColumn,x,y);
    }
};