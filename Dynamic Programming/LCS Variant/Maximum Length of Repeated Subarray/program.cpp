/*similar  to finding longest common substring */
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        
        int dp[n1+2][n2+2];
        int ans=0;
        for(int i=0;i<n1;i++)
            dp[i][0]=0;
        for(int j=0;j<n2;j++)
            dp[0][j]=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};