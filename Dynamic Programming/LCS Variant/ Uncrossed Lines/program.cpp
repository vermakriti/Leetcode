class Solution {
public:
    int dp[505][505];
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i>=nums1.size() || j>=nums2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans;
        if(nums1[i]==nums2[j])
            ans=1+solve(i+1,j+1,nums1,nums2);
        else ans=max(solve(i+1,j,nums1,nums2),solve(i,j+1,nums1,nums2));
        return dp[i][j]=ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,nums1,nums2);
    }
};