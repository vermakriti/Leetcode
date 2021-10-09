/*

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

*/

class Solution {
public:
    int dp[10005];
    int mod=1e9+7;
    int solve(int i,vector<int>& nums){
        if(i>=nums.size()-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        for(int j=nums[i];j>0;j--){
            ans=min(ans,1+solve(i+j,nums)%mod);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(0,nums);
    }
};