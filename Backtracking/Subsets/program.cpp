/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

*/


class Solution {
public:
    void solve(int i,vector<int>&nums,vector<int>&a,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(a);
            return;
        }
        
        // ith element in subset
        a.push_back(nums[i]);
        solve(i+1,nums,a,ans);
        a.pop_back();

        // ith element not in subset
        solve(i+1,nums,a,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        solve(0,nums,a,ans);
        return ans;
        
    }
};