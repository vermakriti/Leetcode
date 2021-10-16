/*

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true

Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:

Input: s = "abc"
Output: false

*/

class Solution {
public:
    bool isPallindrome(int left,int right,string& s){
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        int left=0,right=s.size()-1;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else 
                return isPallindrome(left+1,right,s) || isPallindrome(left,right-1,s);
        }
        return true;
    }
};