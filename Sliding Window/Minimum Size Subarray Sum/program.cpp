class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int i=0,j=0,sum=0,min_size=INT_MAX;
        while(j<n){
            sum+=nums[j];
            if(sum<target)
                j++;
            else if(sum==target){
                min_size=min(min_size,j-i+1);
                j++;
            }
            else{
                while(sum>target){
                    min_size=min(min_size,j-i+1);
                    sum-=nums[i];
                    i++;
                }
                if(sum==target)
                    min_size=min(min_size,j-i+1);
                j++;
            }
        }
        if(min_size==INT_MAX)
            return 0;
        return min_size;
    }
};