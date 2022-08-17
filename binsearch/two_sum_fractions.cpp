#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<vector<int>>& fractions) {
        // Write your code here
        int pairs =0;
        for (int i = 0; i < fractions.size(); ++i) {
            double curr = (double)fractions.at(i).at(0) / (double)fractions.at(i).at(1);
            for (int j = i + 1; j < fractions.size(); ++j ) {
                if (abs(((double)((fractions.at(j)).at(0)) / (double)((fractions.at(j)).at(1))) - (1.0 - curr)) <= 0.00001) {
                    pairs++;
                }
            }
        }
        return pairs;
    }
};
