/*

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.


Example 1:

Input: nums = [2,2,1]
Output: 1

Example 2:

Input: nums = [4,1,2,1,2]
Output: 4

Example 3:

Input: nums = [1]
Output: 1

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

// TC-O(N) SC-O(1)- XOR Operation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int output=nums[0];
        for(int i=1;i<nums.size();i++)
            output^=nums[i];
        return output;
        
    }
};

