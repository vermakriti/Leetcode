/*

Company - Google,Microsoft,Amazon,Facebook,Adobe,Twitter,Qualtrics

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            
            if(mp.find(nums[i]-1)==mp.end()){
                int val=nums[i];
                int count=0;
                while(mp.find(val)!=mp.end()){
                    count++;
                    val++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};