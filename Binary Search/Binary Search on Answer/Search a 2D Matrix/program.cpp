class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        
        int low=col-1,high=0;
        while(low>=0 && high<row){
            
            if(matrix[high][low]==target)
                return true;
            if(matrix[high][low]<target)
                high++;
            else low--;
        }
        return false;
    }
};