class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n=arr.size(),low,high,mid,ans;
        low=0;high=n-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(arr[mid]>arr[(mid+1)%n] && arr[mid]>arr[(mid+n-1)%n]){
                ans=mid;
                break;
            } 
            if(arr[mid]<arr[(mid+1)%n])
                low=mid+1;
            else  high=mid-1; 
        }
        return ans;
    }
};