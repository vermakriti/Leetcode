/*

Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: s = "12345"
Output: ["12345"]
Example 4:

Input: s = "0"
Output: ["0"]

*/




class Solution {
public:
    void solve(int i,string s,string permutation,vector<string>&ans){
        
        if(s.size()==permutation.size()){
           ans.push_back(permutation);
           return;
        }
        if(i==s.size())
            return;
        if(isalpha(s[i])){
            
            permutation.push_back(tolower(s[i]));
            solve(i+1,s,permutation,ans);
            permutation.pop_back();
            
            permutation.push_back(toupper(s[i]));
            solve(i+1,s,permutation,ans);
            permutation.pop_back();
            
        }
        else{
            permutation.push_back(s[i]);
            solve(i+1,s,permutation,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string permutation;
        solve(0,s,permutation,ans);
        return ans;
    }
};