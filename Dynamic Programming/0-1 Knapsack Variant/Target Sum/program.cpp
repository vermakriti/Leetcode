class Solution {
public:
    int dp[22][10000],n;
    vector<int>a;
    int ways(int i,int s){
        if(i>=n&&s==1000)return 1;
        if(i>=n)return 0;
        if(dp[i][s]!=-1)return dp[i][s];
        int ans=0;
        ans=ways(i+1,s-a[i])+ways(i+1,s+a[i]);
        return dp[i][s]=ans;
    }   
    int findTargetSumWays(vector<int>& nums, int S) {
        a=nums;
        n=a.size();
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(auto i:nums)sum+=abs(i);
        if(sum<S)return 0;
        return ways(0,S+1000);
        
    }
};