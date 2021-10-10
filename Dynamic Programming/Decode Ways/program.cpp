/*

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

*/


class Solution {
public:
    int dp[105];
    int solve(int i,string& s){
        if(s[i]=='0')
            return 0;
        if(i>=s.size()-1)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        if(s[i]!='0')
            ans+=solve(i+1,s);
        if(i+1<s.size()){
            int num=(s[i]-'0')*10 + s[i+1]-'0';
            if(num<=26)
                ans+=solve(i+2,s);
        }    
        dp[i]=ans;
        return dp[i];
    }
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        memset(dp,-1,sizeof dp);
        return solve(0,s);
    }
};