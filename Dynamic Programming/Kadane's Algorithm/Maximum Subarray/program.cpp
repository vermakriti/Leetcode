/*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

*/


// TC-O(N) SC-O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans=INT_MIN,sum=0,mx_ele=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0)
                sum=0;
            ans=max(ans,sum);
            mx_ele=max(mx_ele,nums[i]);
        }
        if(mx_ele<0)
            return mx_ele;
        return ans;
    }
};