class Solution {
public:
    int dp[205][10005];
    bool solve(int i,vector<int>& nums,int sum){
        
        if(sum==0)
            return 1;
        if( i>=nums.size() || sum<0)
            return 0;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int ans=0;   
        if(nums[i]<=sum)
            ans=solve(i+1,nums,sum-nums[i]) + solve(i+1,nums,sum);
        else ans=solve(i+1,nums,sum);
        return dp[i][sum]=ans;    
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2)return false;
        memset(dp,-1,sizeof dp);
        return solve(0,nums,sum/2);
    }
};