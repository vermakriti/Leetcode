class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int> count;
        priority_queue<pair<int,char>> q;
        string ans="";
        
        for(int i=0;i<s.size();i++)
            count[s[i]]++;
        
        for(auto it:count){
            q.push({it.second,it.first});
        }
        
        while(!q.empty()){
            int n=q.top().first;
            char ch=q.top().second;
            
            q.pop();
            while(n--) ans+=ch;
        }
        return ans;
    }
};