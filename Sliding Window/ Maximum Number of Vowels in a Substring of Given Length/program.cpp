/*

Given a string s and an integer k.

Return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are (a, e, i, o, u).

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

Example 4:

Input: s = "rhythms", k = 4
Output: 0
Explanation: We can see that s doesn't have any vowel letters.

Example 5:

Input: s = "tryhard", k = 4
Output: 1

*/

class Solution {
public:
    int maxVowels(string s, int k) {
        
        int i=0,j=0,ans=0,vowel=0;
        
        while(j<s.size()){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o'|| s[j]=='u')
                vowel++;
            if(j<k-1){
                j++;
                continue;
            }
            ans=max(ans,vowel);
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u')
                vowel--;
            i++;
            j++;
        }
        ans=max(ans,vowel);
        return ans;
    }
};