/*

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

// TC-O(NlogN + N) SC-O(logN)- internal sorting space 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        vector<int> a;
        sort(intervals.begin(),intervals.end());
        int first = intervals[0][0];
        int second = intervals[0][1];
       
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= second)
                second = max(intervals[i][1],second);
            else{
                a.push_back(first);
                a.push_back(second);
                ans.push_back(a);
                a.clear();
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        a.push_back(first);
        a.push_back(second);
        ans.push_back(a);
        return ans;
    }
};