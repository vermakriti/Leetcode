/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.



Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/

//brute force TC_O(2^N) SC-O(1)
class Solution {
public:
    bool solve(int i,vector<int>& nums,int sum){
        if(sum==0)
            return 1;
        if( i>=nums.size() || sum<0)
            return 0;
        if(nums[i]<=sum)
            ans=solve(i+1,nums,sum-nums[i]) + solve(i+1,nums,sum);
        else ans=solve(i+1,nums,sum);
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2)return false;
        return solve(0,nums,sum/2);
    }
};


//optimize TC-O(N*N) SC-O(N*N)
class Solution {
public:
    int dp[205][10005];
    bool solve(int i,vector<int>& nums,int sum){

        if(sum==0)
            return 1;
        if( i>=nums.size() || sum<0)
            return 0;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int ans=0;
        if(nums[i]<=sum)
            ans=solve(i+1,nums,sum-nums[i]) + solve(i+1,nums,sum);
        else ans=solve(i+1,nums,sum);
        return dp[i][sum]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2)return false;
        memset(dp,-1,sizeof dp);
        return solve(0,nums,sum/2);
    }
};
