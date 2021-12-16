/*

Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
Example 4:

Input: columnTitle = "FXSHRXW"
Output: 2147483647

*/

// TC-O(N) SC-O(26)
class Solution {
public:
    int titleToNumber(string columnTitle) {
        map<char,int> mp;
        for(char ch='A';ch<='Z';ch++){
            mp[ch]=ch-64;
        }
        int ans=0,p=0;
        for(int i=columnTitle.size()-1;i>=0;i--){
            ans+=mp[columnTitle[i]]*pow(26,p);
            p++;
        }
        return ans;
    }
};


// TC-O(N) SC-O(1)
class Solution {
public:
    int titleToNumber(string columnTitle) {

        int ans=0,p=0;
        for(int i=columnTitle.size()-1;i>=0;i--){
            ans+=(columnTitle[i]-64)*pow(26,p);
            p++;
        }
        return ans;
    }
};