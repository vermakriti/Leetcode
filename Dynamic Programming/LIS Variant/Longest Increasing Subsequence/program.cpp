class Solution {
public:
    int dp[2505];
    int fun(int i,vector<int>& nums){
        
        if(i>=nums.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=0;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>nums[i]){
                ans =max(ans,fun(j,nums)+1);
            }
            
        }
        return dp[i]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int ans =INT_MIN;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<nums.size();i++){
            
            ans = max(ans,fun(i,nums));
        }
        return ans+1;
    }
};