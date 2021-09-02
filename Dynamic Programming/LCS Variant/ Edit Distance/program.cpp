class Solution {
public:
    int dp[505][505];
    int solve(int i,int j,string s1,string s2){
        if(i==s1.size())
            return s2.size()-j;
        if(j==s2.size())
            return s1.size()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j])
            ans=solve(i+1,j+1,s1,s2);
        else ans = 1+min({solve(i+1,j,s1,s2),solve(i+1,j+1,s1,s2),solve(i,j+1,s1,s2)});
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,word1,word2);
    }
};