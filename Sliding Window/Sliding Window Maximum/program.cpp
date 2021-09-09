class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        
        multiset<int> s;
        vector<int> v;
        int n=a.size();
        for(int i=0;i<k;i++)
            s.insert(a[i]);
        for(int i=0,j=k;i<n-k,j<n;i++,j++){
            
            auto num=s.rbegin();
            v.push_back(*num);
            s.erase(s.find(a[i]));
            s.insert(a[j]);
        }
        auto num=s.rbegin();
        v.push_back(*num);
        return v;
    }
};