/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/

class Solution {
public:
    void solve(int i,string digits,string s,map<char,string> mp,vector<string>&ans){
        
        if(s.size()==digits.size()){
            ans.push_back(s);
            return;
        }
        if(i>=digits.size())
            return;
        for(int j=0;j<mp[digits[i]].size();j++){
            s.push_back(mp[digits[i]][j]);
            solve(i+1,digits,s,mp,ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        map<char,string> mp;
        mp['0']="";
        mp['1']="";
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        string s="";
        solve(0,digits,s,mp,ans);
        return ans;
    }
};