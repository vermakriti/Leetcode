/*

The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:

We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).

Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.

Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.

Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]

*/

class Solution {
public:
    int dp[10][10][5005];
    int mod=1e9+7;
    int solve(int i,int j,int n,vector<int>&x,vector<int>&y){
        if(i<=0 || i>4 || j<=0 || j>3 || n<0)
            return 0;
        if((i==4 && j==1) || (i==4 && j==3))
                return 0;
        if(n==0)
           return 1;
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        int ans=0;
        for(int k=0;k<8;k++)
            ans=(ans%mod + solve(i+x[k],j+y[k],n-1,x,y)%mod)%mod;
        return dp[i][j][n]=ans;
    }
    int knightDialer(int n) {
        memset(dp,-1,sizeof dp);
        int ans=0;
        vector<int>x{2,2,-2,-2,1,-1,1,-1};
        vector<int>y{1,-1,1,-1,2,2,-2,-2};
        for(int i=1;i<=4;i++){
            for(int j=1;j<=3;j++){
                ans= (ans%mod + solve(i,j,n-1,x,y)%mod)%mod;
            }
        }
        return ans;
    }
};