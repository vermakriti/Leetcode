/*

A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.


Input: nums = [0,1,0,1,1,0,0]
Output: 1

*/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int ones = count(nums.begin(),nums.end(),1);
        int i=0,j=0,ans=nums.size(),count=0,n=nums.size();
        
        while(j<nums.size()+ones && i<nums.size()){
           
            if(j<ones){
                count+=nums[j%n];
                j++;
                continue;
            }
            ans=min(ans,ones-count);
            count-=nums[i++];
            count+=nums[j%n];
            j++;
        }
        return ans;
    }
};