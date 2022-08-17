#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
        {
            return a[2] < b[2];
        }
        else
        {
            return a[1] < b[1];
        }
    }

    vector<int> buildSuffixArray(string s)
    {
        vector<vector<int>> suffixes;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            if (i + 1 < n)
            {
                suffixes.push_back({i, s[i] - 'a', s[i + 1] - 'a'});
            }
            else
            {
                suffixes.push_back({i, s[i] - 'a', -1});
            }
        }
        sort(suffixes.begin(), suffixes.end(), compare);

        vector<int> indices(n, 0);
        for (int k = 4; k < 2 * n; k *= 2)
        {
            int rank = 0;
            int prev_rank = suffixes[0][1];
            suffixes[0][1] = rank;
            indices[suffixes[0][0]] = 0;

            for (int i = 1; i < n; ++i)
            {
                if (suffixes[i][1] == prev_rank &&
                    suffixes[i][2] == suffixes[i - 1][2])
                {
                    prev_rank = suffixes[i][1];
                    suffixes[i][1] = rank;
                }
                else
                {
                    prev_rank = suffixes[i][1];
                    suffixes[i][1] = ++rank;
                }
                indices[suffixes[i][0]] = i;
            }

            for (int i = 0; i < n; ++i)
            {
                int nextIndex = suffixes[i][0] + k / 2;
                if (nextIndex < n)
                {
                    suffixes[i][2] = suffixes[indices[nextIndex]][1];
                }
                else
                {
                    suffixes[i][2] = -1;
                }
            }
            sort(suffixes.begin(), suffixes.end(), compare);
        }
        vector<int> suffixArray(n, 0);
        for (int i = 0; i < n; ++i)
        {
            suffixArray[i] = suffixes[i][0];
        }
        return suffixArray;
    }

    vector<int> kasai(string s, vector<int> &suffixArr)
    {
        int n = s.length();
        vector<int> lcp(n, 0);

        vector<int> inverseSuffix(n, 0);

        for (int i = 0; i < n; ++i)
        {
            inverseSuffix[suffixArr[i]] = i;
        }

        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            if (inverseSuffix[i] == n - 1)
            {
                k = 0;
                continue;
            }
            int j = suffixArr[inverseSuffix[i] + 1];

            while (i + k < n && j + k < n && s[i + k] == s[j + k])
            {
                k++;
            }
            lcp[inverseSuffix[i]] = k;

            if (k > 0)
            {
                k--;
            }
        }
        return lcp;
    }

    int countUniqueSubstrings(string s)
    {
        int n = s.length();
        vector<int> suffixArr = buildSuffixArray(s);
        vector<int> lcp = kasai(s, suffixArr);
        int res = n - suffixArr[0];

        for (int i = 1; i < lcp.size(); ++i)
        {
            res += (n - suffixArr[i]) - lcp[i - 1];
        }
        return res;
    }
};

int main()
{
    string s = "abcde";
    Solution sol;
    cout << "Unique substrings of " << s << ": " << sol.countUniqueSubstrings(s) << "\n";
}