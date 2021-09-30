/*

Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

*/

// Brute force - O(N^2) SC-O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum,size=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>=target)
                    size=min(size,j-i+1);
            }
        }
        if(size==INT_MAX)
            return 0;
        return size;
    }
};

// optimize TC-O(N) SC-O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum=0,size=INT_MAX,i=0,j=0;
        
        while(j<nums.size()){
            sum+=nums[j];
            if(sum<target){
                j++;
            }
            else if(sum==target){
                size=min(size,j-i+1);
                j++;
            }
            else{
                while(sum>target){
                    size=min(size,j-i+1);
                    sum-=nums[i];
                    i++;
                }
                if(sum==target)
                    size=min(size,j-i+1);
                j++;
            }
        }
        if(size==INT_MAX)
            return 0;
        return size;
    }
};