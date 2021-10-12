/*

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int ans=0,i=0,j=0;
        map<int,int> mp;
        
        while(j<nums.size()){
            mp[nums[j]]++;
            auto first = mp.begin();
            auto last = mp.end();
            last--;
            if((last->first - first->first) <= limit)
                ans=max(ans,j-i+1);
            else{
                while((last->first - first->first) > limit){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                        mp.erase(nums[i]);
                    first=mp.begin();
                    last=mp.end();
                    last--;
                    i++;
                } 
                if((first->first - last->first) <= limit)
                    ans=max(ans,j-i+1);
            }
            
            j++;
        }
        return ans;
    }
};


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int ans=0,i=0,j=0;
        map<int,int> mp;
        
        while(j<nums.size()){
            mp[nums[j]]++;
            auto first = mp.begin();
            auto last = mp.end();
            last--;
            while((last->first - first->first) > limit){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                first=mp.begin();
                last=mp.end();
                last--;
                i++;
            } 
            ans=max(ans,j-i+1);   
            j++;
        }
        return ans;
    }
};