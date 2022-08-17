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
    int n;
    cin >> n;
    string dirs;
    cin >> dirs;
    auto graph = vector<vector<char>>(2 * n + 1, vector<char>(n, '.'));
    pii cursor = make_pair(n, 0);
    int ymin = INT_MAX;
    int ymax = INT_MIN;

    for (char c : dirs)
    {
        if (c == '^')
        {
            graph[cursor.first][cursor.second] = '/';
            ymin = min(ymin, cursor.first);
            ymax = max(ymax, cursor.first);
            --cursor.first;
        }
        else if (c == 'v')
        {
            ++cursor.first;
            graph[cursor.first][cursor.second] = '\\';
            ymin = min(ymin, cursor.first);
            ymax = max(ymax, cursor.first);
        }
        else
        {
            graph[cursor.first][cursor.second] = '_';
            ymin = min(ymin, cursor.first);
            ymax = max(ymax, cursor.first);
        }
        ++cursor.second;
        // ymin = min(ymin, cursor.first);
        // ymax = max(ymax, cursor.first);
    }
    // for (auto v : graph)
    // {
    //     for (char c : v)
    //     {
    //         cout << c;
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    for (int i = ymin; i <= ymax; ++i)
    {
        for (char c : graph[i])
        {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}