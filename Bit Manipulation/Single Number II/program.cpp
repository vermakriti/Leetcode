/*

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.


Example 1:

Input: nums = [2,2,3,2]
Output: 3

Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99

*/

// TC-O(N) SC-O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto it:mp){
            if(it.second==1)
                return it.first;
        }
        return -1;
    }
};

