/*

You have some apples, where arr[i] is the weight of the i-th apple.  You also have a basket that can carry up to 5000 units of weight.

Return the maximum number of apples you can put in the basket.

 

Example 1:

Input: arr = [100,200,150,1000]
Output: 4
Explanation: All 4 apples can be carried by the basket since their sum of weights is 1450.

Example 2:

Input: arr = [900,950,800,1000,700,800]
Output: 5
Explanation: The sum of weights of the 6 apples exceeds 5000 so we choose any 5 of them.
 

Constraints:

1 <= arr.length <= 10^3
1 <= arr[i] <= 10^3

*/

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int units=0,apple=0;
        for(int i=0;i<arr.size();i++){
            units+=arr[i];
            if(units<=5000)
                apple++;
            else break;
        }
        return apple;
    }
};