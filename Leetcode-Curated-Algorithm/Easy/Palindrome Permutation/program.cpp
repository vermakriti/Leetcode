/*

Company - FaceBook, Microsoft,Goldman Sachs

Given a string s, return true if a permutation of the string could form a palindrome.

Example 1:

Input: s = "code"
Output: false

Example 2:

Input: s = "aab"
Output: true

Example 3:

Input: s = "carerac"
Output: true
 

Constraints:

1 <= s.length <= 5000
s consists of only lowercase English letters.

*/

// two pass solution TC-O(N) SC-(26) - size of map (we can consider it as constant space)

class Solution {
public:
    bool canPermutePalindrome(string s) {
       
        map<char,int> count;
        int odd=0;
        for(auto ele:s)
            count[ele]++;
        for(auto ele:count){
            if(ele.second&1)
                odd++;
        }
        if(odd==1 || odd==0)return true;
        return false;
    }
};

// single pass solution TC-O(N) SC-(26) size of map (we can consider it as constant space)

class Solution {
public:
    bool canPermutePalindrome(string s) {
       
        map<char,int> count;
        int charCount=0;
        for(auto ch:s){
            count[ch]++;
            if(count[ch]%2==0)
                charCount--;
            else  charCount++;
        }
        return charCount<=1;
    }
};