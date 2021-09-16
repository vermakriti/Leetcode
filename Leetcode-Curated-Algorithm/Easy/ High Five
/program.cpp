/*

Company- Goldman Sachs

Given a list of the scores of different students, items, where items[i] = [IDi, scorei] represents one score from a student with IDi, calculate each student's top five average.

Return the answer as an array of pairs result, where result[j] = [IDj, topFiveAveragej] represents the student with IDj and their top five average. Sort result by IDj in increasing order.

A student's top five average is calculated by taking the sum of their top five scores and dividing it by 5 using integer division.


Example 1:

Input: items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]

Example 2:

Input: items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
Output: [[1,100],[7,100]]
 

Constraints:

1 <= items.length <= 1000
items[i].length == 2
1 <= IDi <= 1000
0 <= scorei <= 100
For each IDi, there will be at least five scores.

*/


class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        
        map<int,priority_queue<int>> hash;
        vector<vector<int>> ans;
        
        for(int i=0;i<items.size();i++)
            hash[items[i][0]].push(items[i][1]);
        for(auto ele:hash){
            vector<int> v;
            v.push_back(ele.first);
            long long sum=0;
            int i=1;
            while(i<=5){
                sum+=ele.second.top();
                ele.second.pop();
                i++;
            }
            v.push_back(sum/5);
            ans.push_back(v);
        }
        return ans;
    }
};