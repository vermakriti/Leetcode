// Check if Every Row and Column Contains All Numbers 

/*
An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).

Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

 
Example 1:

Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.

*/

class Solution {
public:
    bool isValidRow(int row,vector<vector<int>>& matrix){
        
        map<int,int> mp;
        for(int i=0;i<matrix.size();i++){
            mp[matrix[row][i]]++;
        }
        for(int i=1;i<=matrix.size();i++){
            if(mp.find(i)==mp.end())
                return false;
        }
        return true;
    }
    bool isValidCol(int col,vector<vector<int>>& matrix){
        
        map<int,int> mp;
        for(int i=0;i<matrix.size();i++){
            mp[matrix[i][col]]++;
        }
        for(int i=1;i<=matrix.size();i++){
            if(mp.find(i)==mp.end())
                return false;
        }
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        
        for(int i=0;i<matrix.size();i++){
            if(!isValidRow(i,matrix))
                return false;
        }
        for(int i=0;i<matrix.size();i++){
            if(!isValidCol(i,matrix))
                return false;
        }
        return true;
    }
};