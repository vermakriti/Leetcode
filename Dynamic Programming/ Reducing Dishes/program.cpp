/*

A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People don't like the dishes. No dish is prepared.

Example 4:

Input: satisfaction = [-2,5,-1,0,3,-3]
Output: 35

*/

class Solution {
public:
    int dp[505][505];
    int solve(int i,int t,vector<int>& satisfaction){
    
        if(i>=satisfaction.size() || t>satisfaction.size())
            return 0;
        if(dp[i][t]!=-1)
            return dp[i][t];
        int ans = max(solve(i+1,t+1,satisfaction)+satisfaction[i]*t ,solve(i+1,t,satisfaction));
        return dp[i][t]=ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
        memset(dp,-1,sizeof dp);
        int n1=solve(0,1,satisfaction);
        memset(dp,-1,sizeof dp);
        reverse(satisfaction.begin(),satisfaction.end());
        int n2=solve(0,1,satisfaction);
        
        return max(n1,n2);
    }
};