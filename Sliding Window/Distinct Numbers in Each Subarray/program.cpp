/*

Given an integer array nums and an integer k, you are asked to construct the array ans of size n-k+1 where ans[i] is the number of distinct numbers in the subarray nums[i:i+k-1] = [nums[i], nums[i+1], ..., nums[i+k-1]].
Return the array ans.

Example 1:

Input: nums = [1,2,3,2,2,1,3], k = 3
Output: [3,2,2,2,3]
Explanation: The number of distinct elements in each subarray goes as follows:
- nums[0:2] = [1,2,3] so ans[0] = 3
- nums[1:3] = [2,3,2] so ans[1] = 2
- nums[2:4] = [3,2,2] so ans[2] = 2
- nums[3:5] = [2,2,1] so ans[3] = 2
- nums[4:6] = [2,1,3] so ans[4] = 3


*/

// TC-O(N) SC-O(N)
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int i=0;i<k;i++)
            mp[nums[i]]++;
        ans.push_back(mp.size());
        
        for(int i=k;i<nums.size();i++){
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)
                mp.erase(nums[i-k]);
            mp[nums[i]]++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};