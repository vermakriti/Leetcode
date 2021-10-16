/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:

Input: nums = [1,2,3]
Output: 3


*/

class Solution {
public:
    int dp[105];
    int solve(int i,int n,vector<int>& nums){
        if(i>n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans = max(solve(i+2,n,nums)+nums[i],solve(i+1,n,nums));
        return dp[i]=ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        memset(dp,-1,sizeof dp);
        int n=nums.size();
        int mx1 = solve(0,n-2,nums);
        memset(dp,-1,sizeof dp);
        int mx2 = solve(1,n-1,nums);
        return max(mx1,mx2);
    }
};