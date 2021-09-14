/*

You have a data structure of employee information, which includes the employee's unique id, their importance value, and their direct subordinates' id.

You are given an array of employees employees where:

employees[i].id is the ID of the ith employee.
employees[i].importance is the importance value of the ith employee.
employees[i].subordinates is a list of the IDs of the subordinates of the ith employee.
Given an integer id that represents the ID of an employee, return the total importance value of this employee and all their subordinates.

 

Example 1:


Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
Output: 11
Explanation: Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3.
They both have importance value 3.
So the total importance value of employee 1 is 5 + 3 + 3 = 11.

Example 2:


Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
Output: -3
 

Constraints:

1 <= employees.length <= 2000
1 <= employees[i].id <= 2000
All employees[i].id are unique.
-100 <= employees[i].importance <= 100
One employee has at most one direct leader and may have several subordinates.
id is guaranteed to be a valid employee id.

*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int> &visited,map<int,int>&mp,int&ans){
        
        visited[node]=1;
        ans+=mp[node];
        for(auto child:adj[node]){
            if(!visited[child])
                dfs(child,adj,visited,mp,ans);
        }
        
    }
    int getImportance(vector<Employee*> employees, int id) {
        
        map<int,int>mp;
        vector<int> adj[2005];
        vector<int> visited(2005,0);
        int ans=0;
        
        for(int i=0;i<employees.size();i++){
            for(int j=0;j<employees[i]->subordinates.size();j++){
                adj[employees[i]->id].push_back(employees[i]->subordinates[j]);
            }        
        }
        for(int i=0;i<employees.size();i++){
            mp[employees[i]->id]=employees[i]->importance;
        }
        dfs(id,adj,visited,mp,ans);
        return ans;
    }
};