/*

You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

If the length of the word is 1 or 2 letters, change all letters to lowercase.
Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
Return the capitalized title.

Input: title = "capiTalIze tHe titLe"
Output: "Capitalize The Title"

*/


class Solution {
public:
    string capitalizeTitle(string title) {
        
        stringstream ss(title);
        string word,ans;
        
        while(ss>>word){
            
            if(word.size()==1 || word.size()==2){
                string s;
                for(int i=0;i<word.size();i++)
                    s.push_back(tolower(word[i]));
                ans+=s;
            }    
            else{
                string s;
                for(int i=0;i<word.size();i++){
                    if(i==0) s.push_back(toupper(word[i]));
                    else s.push_back(tolower(word[i]));
                }
                ans+=s;
            }
            ans+=" ";
        }
        ans.pop_back();
        return ans;
        
    }
};