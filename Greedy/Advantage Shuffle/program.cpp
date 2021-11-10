/*

You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].

Return any permutation of nums1 that maximizes its advantage with respect to nums2.

 

Example 1:

Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
Output: [2,11,7,15]

Example 2:

Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
Output: [24,32,8,12]

*/

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> arr2=nums2,arr1,ans;
        map<int,vector<int>> mp;
        
        sort(nums1.begin(),nums1.end());
        sort(arr2.begin(),arr2.end());
        
        int j=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]>arr2[j])
                mp[arr2[j++]].push_back(nums1[i]);
            else arr1.push_back(nums1[i]);
        }
        while(j<arr2.size()){
            mp[arr2[j++]].push_back(arr1.back());
            arr1.pop_back();
        }
        
        for(auto it:nums2){
            ans.push_back(mp[it].back());
            mp[it].pop_back();
            
        }
        
        return ans;
    }
};