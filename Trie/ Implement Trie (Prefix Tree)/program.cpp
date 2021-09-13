/*

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]

Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

*/

class TrieNode{
    public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode():children(26){
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=nullptr;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode*curr=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->children[index]==nullptr)
                curr->children[index]=new TrieNode();
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    bool search(string word) {
        TrieNode*curr=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->children[index]==nullptr)
               return false;
            curr=curr->children[index];
        }
        if(curr->isEnd)
            return true;
        return false;
    }
    bool startsWith(string prefix) {
        TrieNode*curr=root;
        for(int i=0;i<prefix.size();i++){
            int index=prefix[i]-'a';
            if(curr->children[index]==nullptr)
               return false;
            curr=curr->children[index];
        }
        return true;
    }
};
