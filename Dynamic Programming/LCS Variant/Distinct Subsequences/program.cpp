class Solution {
public:
    int dp[1005][1005];
    int solve(int i,int j,string &s,string &t){
        if(j==t.size())
            return 1;
        if(i==s.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        if(s[i]==t[j])
            ans=solve(i+1,j+1,s,t)+solve(i+1,j,s,t);
        else ans=solve(i+1,j,s,t);
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,s,t);
    }
};