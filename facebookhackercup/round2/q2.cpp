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

vector<pii> bfs(int start, vi &freq, vector<vi> &graph)
{
    set<pii> keep;
    queue<vector<int>> q;
    unordered_set<int> seen;
    q.push(vector<int>{start});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (freq[curr[curr.size() - 1]] == freq[start])
        {
            for (int i = 0; i < curr.size() - 1; ++i)
            {
                if (curr[i] < curr[i + 1])
                {
                    keep.emplace(make_pair(curr[i], curr[i + 1]));
                }
                else
                {
                    keep.emplace(make_pair(curr[i + 1], curr[i]));
                }
            }
        }
        seen.emplace(curr[curr.size() - 1]);
        for (int i : graph[curr[curr.size() - 1]])
        {
            if (seen.find(i) == seen.end())
            {
                auto n = curr;
                n.push_back(i);
                q.push(n);
            }
        }
    }
    vector<pii> pairs;
    for (auto it : keep)
    {
        pairs.push_back(it);
    }
    return pairs;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; ++t)
    {
        int N;
        cin >> N;
        vector<vi> graph(N + 1);
        for (int i = 0; i < N - 1; ++i)
        {
            int a, b;
            cin >> a;
            cin >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        // for (vi vv : graph)
        // {
        //     for (int i : vv)
        //     {
        //         cout << i << ", ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        vi F(N + 1);
        for (int i = 1; i <= N; ++i)
        {
            cin >> F[i];
        }
        set<pii> suss;
        for (int i = 0; i < graph.size(); ++i)
        {
            for (pii sus : bfs(i, F, graph))
            {
                // cout << "(" << sus.first << ", " << sus.second << "), ";
                suss.emplace(sus);
            }
            // cout << "\n";
        }
        cout << "Case #" << t << ": " << N - 1 - (int)(suss.size()) << "\n";
    }
    return 0;
}