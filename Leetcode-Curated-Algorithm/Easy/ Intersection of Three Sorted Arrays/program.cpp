/*
Company - FaceBook

Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.

Example 2:

Input: arr1 = [197,418,523,876,1356], arr2 = [501,880,1593,1710,1870], arr3 = [521,682,1337,1395,1764]
Output: []
 

Constraints:

1 <= arr1.length, arr2.length, arr3.length <= 1000
1 <= arr1[i], arr2[i], arr3[i] <= 2000

*/

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        
        vector<int> ans;
        int i=0,j=0,k=0;
        while(i<arr1.size() && j<arr2.size() && k<arr3.size()){
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
                ans.push_back(arr1[i]);
                i++;
                j++;
                k++;
            }    
            else{
                int mx=max({arr1[i],arr2[j],arr3[k]});
                if(arr1[i]==mx && arr2[j]!=mx && arr3[k]!=mx){
                    j++;
                    k++;
                }
                else if(arr1[i]!=mx && arr2[j]==mx && arr3[k]!=mx){
                    i++;
                    k++;
                }
                else  if(arr1[i]!=mx && arr2[j]!=mx && arr3[k]==mx){
                    i++;
                    j++;
                }
                else  if(arr1[i]==mx && arr2[j]==mx && arr3[k]!=mx)
                    k++;
                else  if(arr1[i]==mx && arr2[j]!=mx && arr3[k]==mx)
                    j++;
                else  if(arr1[i]!=mx && arr2[j]==mx && arr3[k]==mx)
                    i++;
            }
        }
        return ans;
    }
};