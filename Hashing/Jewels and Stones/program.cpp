/*

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0

*/

// TC-O(N^2) SC-O(1)
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int stone=0;
        for(int i=0;i<jewels.size();i++){
            for(int j=0;j<stones.size();j++){
                if(jewels[i]==stones[j])
                    stone++;
            }
        }
        return stone;
    }
};

//TC-O(M+N) SC-O(26*2)
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        map<char,int> mp;
        int stone=0;
        for(int i=0;i<stones.size();i++)
            mp[stones[i]]++;
        for(int i=0;i<jewels.size();i++)
            stone+=mp[jewels[i]];
        return stone;
    }
};

