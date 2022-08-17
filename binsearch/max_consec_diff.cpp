// #include "solution.hpp"
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        // Write your code here
        int nummax = INT_MIN;
        for (int i : nums) {
            nummax = max(i, nummax);
        }
        vector<int> pval(nummax, 0);
        
        for (int &i : pval) {
            cout << i << ", ";
        }
        
        for (int i =0; i < n; ++i) {
            pval[nums[i] - 1]++;
        }
        
        for (int i = 1; i < n; ++i) {
            pval[nums[i] - 1] += pval[nums[i-1] - 1];
        }
        
        for (auto &i : pval) {
            cout << i << ", ";
        }
        cout << "\n";
        
        vector<int> final(n, -1);
        
        for (int i = n - 1; i >=0; --i) {
            final[pval[nums[i]] - 1] = nums[i];
        }
        for (auto &i : final) {
            cout << i << " ";
        }
        cout << "\n";
        
        
        int diffmax = INT_MIN;
        for (int i = 0; i < n -1; ++i) {
            diffmax = max(diffmax, final[i+1] - final[i]);
        }
        return diffmax;
    }
};
