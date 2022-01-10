/*

You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6

*/

class Solution {
public:
   
    int longestPalindrome(vector<string>& words) {
        
        int ans=0;
        bool flag=false;
        map<string,int> mp;
        
        for(auto s:words)
            mp[s]++;
        
        for(auto it:mp){
            
            string x=it.first;
            string y=x;
            reverse(y.begin(),y.end());
            
            if(x==y){
                int count = mp[x]/2;
                ans+=4*count;
                if(mp[x]%2==0) mp[x]=0;
                else if(!flag){
                    flag=true;
                    ans+=2;
                    mp[x]=0;
                }
            }
            else{
                int count = min(mp[x],mp[y]);
                ans+=4*count;
                mp[x]-= count;
                mp[y]-= count;
            }
        }
        return ans;
    
    }
};