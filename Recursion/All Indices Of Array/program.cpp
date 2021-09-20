/*

1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number x. 
4. You are required to find the all indices at which x occurs in array a.
5. Return an array of appropriate size which contains all indices at which x occurs in array a.

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{
    static vector<int> ans;
    if(idx==arr.size())
        return ans;
    if(arr[idx]==data){
        ans.push_back(idx);
    }    
    return allIndex(arr,idx+1,data,count);
}

int main() {
  int n ;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  int data;
  cin >> data;
  vector<int> ans = allIndex(arr, 0, data, 0);
  if (ans.size() == 0) {
    cout << endl;
    return 0;
  }
  for (int ele : ans) cout << ele << endl;

  return 0;
}