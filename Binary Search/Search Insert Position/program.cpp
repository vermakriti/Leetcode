class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0])
            return 0;
        int low=0,high=nums.size()-1,mid,ans=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                ans=mid;
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans+1;
    }
};