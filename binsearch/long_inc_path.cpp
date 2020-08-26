#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(const pair<int, int> &pos, const vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> n = neighbours(pos, matrix);

        if (n.size() == 0)
        {
            return 1;
        }
        else
        {
            int mmax = 0;
            for (int i = 0; i < (int)(n.size()); ++i)
            {
                mmax = max(mmax, dfs(n.at(i), matrix));
            }

            return 1 + mmax;
        }
    }

    vector<pair<int, int>> neighbours(const pair<int, int> &pos, const vector<vector<int>> &matrix)
    {
        auto row = vector<int>{-1, 1, 0, 0};
        auto col = vector<int>{0, 0, -1, 1};

        vector<pair<int, int>> neighs;
        int M = matrix.size();
        int Mx = matrix.at(0).size();

        for (int i = 0; i < 4; i++)
        {
            auto delta = pair<int, int>(pos.first + row.at(i), pos.second + col.at(i));
            if (delta.first >= 0 && delta.first < M && delta.second >= 0 && delta.second < Mx)
            {
                if (matrix.at(delta.first).at(delta.second) > matrix.at(pos.first).at(pos.second))
                    neighs.emplace_back(delta);
            }
        }
        return neighs;
    }

    int solve(const vector<vector<int>> &matrix)
    {
        // Write your code here
        int big = 0;

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix.at(i).size(); ++j)
            {
                big = max(big, dfs(pair<int, int>(i, j), matrix));
            }
        }
        return big;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix{{3, 9, 64}};
    int ans = sol.solve(matrix);
    printf("result: %d\n", ans);
    return ans;
}