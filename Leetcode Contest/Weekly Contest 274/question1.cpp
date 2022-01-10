/*

Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

Example 1:

Input: s = "aaabbb"
Output: true

*/

class Solution {
public:
    bool checkString(string s) {
        
        int A=-1,B=INT_MAX;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')
                A=i;
            else if(B==INT_MAX)
                B=i;
        }
        return (A<B);
    }
};