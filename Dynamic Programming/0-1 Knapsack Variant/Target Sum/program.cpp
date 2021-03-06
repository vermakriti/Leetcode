/*

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

*/


class Solution {
public:
    int dp[22][10000],n;
    vector<int>a;
    int ways(int i,int s){
        if(i>=n&&s==1000)return 1;
        if(i>=n)return 0;
        if(dp[i][s]!=-1)return dp[i][s];
        int ans=0;
        ans=ways(i+1,s-a[i])+ways(i+1,s+a[i]);
        return dp[i][s]=ans;
    }   
    int findTargetSumWays(vector<int>& nums, int S) {
        a=nums;
        n=a.size();
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(auto i:nums)sum+=abs(i);
        if(sum<S)return 0;
        return ways(0,S+1000);
        
    }
};