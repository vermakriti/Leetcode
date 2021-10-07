/*

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x k cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on...
Return the minimum cost to paint all houses.

Example 1:

Input: costs = [[1,5,3],[2,9,4]]
Output: 5
Explanation:
Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.

Example 2:

Input: costs = [[1,3],[2,4]]
Output: 5

*/

class Solution {
public:
    int dp[105][25];
    int solve(int i,int j,vector<vector<int>>& costs){
        if(i>=costs.size() || j>=costs[0].size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=0;k<costs[0].size();k++){
            if(k==j) continue;
            ans=min(ans,costs[i][j]+solve(i+1,k,costs));
        }
        return dp[i][j]=ans;
    }
    int minCostII(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof dp);
        int ans=INT_MAX;
        for(int j=0;j<costs[0].size();j++){
            int temp=solve(0,j,costs);
            ans=min(ans,temp);
        }
        return ans;
    }
};