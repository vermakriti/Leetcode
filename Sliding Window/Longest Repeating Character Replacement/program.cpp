/*

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.


*/

class Solution {
public:
    char maxValueKey(unordered_map<char,int>&mp){
        
        int count=0;
        char key;
        for(auto it:mp){
            if(it.second > count){
                key=it.first;
                count=it.second;
            }
        }
        return key;
    }
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> mp;
        int i=0,j=0,ans=0;
        
        while(j<s.size()){
            
            mp[s[j]]++;
            char key=maxValueKey(mp);
            while(j-i+1 - mp[key] > k){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};