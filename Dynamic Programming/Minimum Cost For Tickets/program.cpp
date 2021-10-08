/*

You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.

Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.

*/

class Solution {
public:
    int dp[370];
    int solve(int i,vector<int>& days, vector<int>& costs){
        if(i>=days.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int firstDayOfWeek = i,lastDayOfWeek = days[i]+7;
        while( firstDayOfWeek < days.size() && days[firstDayOfWeek] <lastDayOfWeek ){
            firstDayOfWeek++;
        }
        
        int firstDayOfMonth = i,lastDayOfMonth = days[i]+30;
        while( firstDayOfMonth < days.size() && days[firstDayOfMonth] <lastDayOfMonth ){
            firstDayOfMonth++;
        }
        int ans = min({costs[0]+solve(i+1,days,costs),costs[1]+solve(firstDayOfWeek,days,costs),
                      costs[2]+solve(firstDayOfMonth,days,costs)});
        return dp[i]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof dp);
        return solve(0,days,costs);
    }
};