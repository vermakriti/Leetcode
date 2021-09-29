/*

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

// brute force -  TC -  O(N^2*N) - O(N^2)- for generating all substrings, O(N)-for checking characters repetation  SC - O(M)

class Solution {
public:
    bool check(int i,int j,string &s){
        map<char,int> mp;
        for(;i<=j;i++){
            mp[s[i]]++;
            if(mp[s[i]]>1)
                return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s){

        int length=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(i,j,s))
                    length=max(length,j-i+1);
            }
        }
        return length;
    }
};


// optimize - TC-O(2*N) SC-O(M)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i=0,j=0,ans=0;
        map<char,int> mp;
        
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                if(mp.size()==j-i+1)
                    ans=max(ans,j-i+1);
                j++;
            }
            
        }
        return ans;
    }
};