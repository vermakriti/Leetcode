class Solution {
public:
    int binarySearch(vector<int>& nums, int target,int low,int high){
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==target)
                return 0;
            return -1;
        }    
        int low=0,high=n-1,mid,ans;
        
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]<nums[(mid+1)%n] && nums[mid]<nums[(mid+n-1)%n])
                break;
            if(nums[mid]<nums[high])
                high=mid-1;
            else low=mid+1;
        }
        ans=binarySearch(nums,target,0,mid-1);
        if(ans!=-1)return ans;
        ans=binarySearch(nums,target,mid,n-1);
        return ans;
    }
};