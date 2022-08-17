#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); ++i)
        {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp;
        dp[0] = 0;
        for (int i = 0; i < jobs.size(); ++i)
        {
            // knapsack
            int val = prev(dp.lower_bound(jobs[i][1]))->second + jobs[i][2];
            if (val > prev(dp.end())->second)
            {
                dp[jobs[i][0]] = val;
            }
        }
        return prev(dp.end())->second;
    }
};