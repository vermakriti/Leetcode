/*

Numbers can be regarded as the product of their factors.

For example, 8 = 2 x 2 x 2 = 2 x 4.
Given an integer n, return all possible combinations of its factors. You may return the answer in any order.

Note that the factors should be in the range [2, n - 1].

 

Example 1:

Input: n = 1
Output: []

Example 2:

Input: n = 12
Output: [[2,6],[3,4],[2,2,3]]

Example 3:

Input: n = 37
Output: []

Example 4:

Input: n = 32
Output: [[2,16],[4,8],[2,2,8],[2,4,4],[2,2,2,4],[2,2,2,2,2]]

*/

class Solution {
public:
    int mod=1e9+7;
    void allFactor(int& n,vector<int>& factor){
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                if(n/i==i)
                    factor.push_back(n/i);
                else{
                    factor.push_back(n/i);
                    factor.push_back(i);
                }
            }
        }
    }
    
    void solve(int i,int n,vector<int>& factor,vector<int>temp,long long prod,vector<vector<int>> &ans){
        
        if(i>=factor.size() || prod>n)
            return;
        if(prod==n){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<factor.size();j++){
            int p = prod;
            prod = (prod%mod * factor[j]%mod)%mod;
            temp.push_back(factor[j]);
            solve(j,n,factor,temp,prod,ans);
            temp.pop_back();
            prod = p;
        }
        
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        if(n==1)
            return ans;
        vector<int> factor;
        allFactor(n,factor);
        if(factor.size()==0)
            return ans;
        vector<int> temp;
        solve(0,n,factor,temp,1,ans);
        return ans;
    }
};