/*
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

 

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
 

Constraints:

1 <= s.length <= 5 * 104
0 <= k <= 50

*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        map<int,int> mp;
        int i=0,j=0,ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()<=k){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                if(mp.size()<=k){
                    ans=max(ans,j-i+1);
                }
                j++;
            }
        }
        return ans;
    }
};