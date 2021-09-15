/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]

Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/

class Solution {
public:
    class TrieNode{
        public:
        int count=0;
        vector<TrieNode*>children;
        TrieNode():children(26){
            count=0;
            for(int i=0;i<26;i++)
                children[i]=nullptr;
        }
    };
    TrieNode*root;
    Solution(){
        root=new TrieNode();
    }
    void add(string word){
        TrieNode*curr=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->children[index]==nullptr)
                curr->children[index]=new TrieNode();
            curr=curr->children[index];
            curr->count++;
          
        }
    }
    string prefixSearch(string word,int count){
        TrieNode*curr=root;
        string s="";
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->children[index] && curr->children[index]->count==count){
                s+=word[i];
                curr=curr->children[index];
            }    
            else break;
        }
        return s;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        for(int i=0;i<strs.size();i++){
            add(strs[i]);
        }
        return prefixSearch(strs[0],strs.size());
    }
};