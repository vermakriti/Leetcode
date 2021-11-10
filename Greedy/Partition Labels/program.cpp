/*

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Return a list of integers representing the size of these parts.

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

Example 2:

Input: s = "eccbbbbdec"
Output: [10]

*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        map<int,int> mp;
        vector<int> ans;
        int j=0,first=0;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        for(int i=0;i<s.size();i++){
            j=max(j,mp[s[i]]);
            if(i==j){
                ans.push_back(j-first+1);
                j=0;
                first=i+1;
            }
        }
        return ans;
    }
};