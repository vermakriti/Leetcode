/*

On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

 

Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.

Example 2:

Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000

*/

class Solution {
public:
    double dp[30][30][105];
    double solve(int row,int col,int&n,int k,vector<int> &x,vector<int> &y){
        
        if(row<0 || row>=n || col<0 || col>=n) return 0;
        if(k==0) return 1;
        if(dp[row][col][k]!=0.0) 
            return dp[row][col][k];
        double ans=0.0;
        for(int i=0;i<8;i++){
            ans+=(0.125)*solve(row+x[i],col+y[i],n,k-1,x,y);
        }
        return dp[row][col][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        
        vector<int> x{-1,-1,-2,-2,1,1,2,2};
        vector<int> y{2,-2,1,-1,2,-2,1,-1};
        
        memset(dp,0.0,sizeof dp);
        return solve(row,column,n,k,x,y);
    }
};