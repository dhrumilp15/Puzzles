#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl "\n";
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    auto start = unordered_map<int, int>();
    auto stop = unordered_map<int, int>();
    int N, M;
    cin >> N >> M;
    vi colours;
    for (int i = 0; i < N; ++i)
    {
        int c;
        cin >> c;
        colours.push_back(c);
    }
    for (int i = 0; i < N; ++i)
    {
        if (start.find(colours[i]) == start.end())
        {
            start[colours[i]] = i;
        }
    }
    for (int i = N - 1; i >= 0; --i)
    {
        stop[colours[i]] = max(stop[colours[i]], i);
    }
    int total = 0;

    for (int i = 0; i < M; ++i)
    {
        int startc, stopc;
        cin >> startc >> stopc;
        if (start.find(startc) != start.end() && stop.find(stopc) != stop.end())
        {
            if (stop.find(stopc)->second >= start.find(startc)->second)
            {
                total = max(total, stop[stopc] - start[startc] + 1);
            }
        }
    }
    cout << total;

    return 0;
}