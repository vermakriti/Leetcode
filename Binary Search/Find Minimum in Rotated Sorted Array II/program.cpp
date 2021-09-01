class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int low=0,high=n-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]<nums[(mid+1)%n] && nums[mid]<nums[(mid+n-1)%n])
                break;
            if(nums[mid]==nums[(mid+1)%n] && nums[mid]<nums[(mid+n-1)%n])
                break;
            if(nums[mid]==nums[high])
                high--;
            else if(nums[mid]<nums[high])
                high=mid-1;
            else low=mid+1;
        }
        return nums[mid];
    }
};