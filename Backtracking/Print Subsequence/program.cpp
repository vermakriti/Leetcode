/*

1. You are given a string str.
2. Complete the body of printSS function - without changing signature - to calculate and print all subsequences of str.

*/

#include <iostream>
using namespace std;

void printSS(int i,string ques, string ans){
    cout<<ans<<"\n";
    if(i>=ques.size())
        return;
    for(int j=i;j<ques.size();j++){
        ans.push_back(ques[j]);
        printSS(j+1,ques,ans);
        ans.pop_back();
    }    
    
    
}

int main(){
    string str;
    cin >> str;
    printSS(0,str, "");
}