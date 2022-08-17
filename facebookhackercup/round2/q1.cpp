#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
#define endl "\n";
#define f first;
#define s second;

struct myComp
{
    constexpr bool operator()(
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept
    {
        return a.second < b.second;
    }
};

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; ++t)
    {
        int N, M;
        cin >> N >> M;
        vector<int> style(M);
        for (int i = 0; i < M; ++i)
        {
            cin >> style[i];
        }

        vector<vector<int>> roundstyles(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> roundstyles[i][j];
            }
        }
        unordered_map<int, int> rowstyle; // style->position
        vector<int> modelchanges(M, 0);
        priority_queue<pii, vector<pii>, myComp> modelsorder;
        for (int i = 0; i < N; ++i)
        {
            for (int i = 0; i < M; ++i)
            {
                modelsorder.emplace(make_pair(i, modelchanges[i]));
            }
            // cout << "style: ";
            // for (int i = 0; i < M; ++i)
            // {
            //     cout << style[i] << ", ";
            // }
            // cout << "\n";
            for (int j = 0; j < M; ++j)
            {
                ++rowstyle[roundstyles[i][j]];
            }
            // allocate models in order of the number of times that they've changed styles
            vector<int> toallocate;
            // cout << "modelsorder: ";
            while (!modelsorder.empty())
            {
                auto model = modelsorder.top();
                modelsorder.pop();
                // cout << "(" << model.first << ", " << model.second << "), ";
                auto val = rowstyle.find(style[model.first]);

                if (val != rowstyle.end()) // model doesn't need to change
                {
                    --val->second;
                    if (val->second == 0)
                    {
                        rowstyle.erase(val->first);
                    }
                }
                else
                {
                    toallocate.push_back(model.first);
                }
            }
            // cout << "\n";
            // cout << "rowstyle: ";
            // for (auto it : rowstyle)
            // {
            //     cout << "(" << it.first << ", " << it.second << "), ";
            // }
            // cout << "\n";
            if (!rowstyle.empty())
            {
                auto it = rowstyle.begin();
                for (int i : toallocate)
                {
                    // cout << i << ", ";
                    ++modelchanges[i];
                    style[i] = it->first;
                    --it->second;
                    if (it->second == 0)
                    {
                        ++it;
                    }
                }
                // cout << "\n";
                rowstyle.clear();
            }
        }
        int totalchanges = 0;
        // cout << "modelchanges: ";
        for (int i : modelchanges)
        {
            totalchanges += max(i - 1, 0);
            // cout << i << ", ";
        }
        // cout << "\n";
        cout << "Case #" << t << ": " << totalchanges << "\n";
    }
    return 0;
}