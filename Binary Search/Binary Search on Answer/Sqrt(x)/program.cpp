class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int low=1,high=x,mid,ans;
        while(low<=high){
            mid=low+(high-low)/2;
            if((1LL)*mid*mid==x)
                return mid;
            if((1LL)*mid*mid<x){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};