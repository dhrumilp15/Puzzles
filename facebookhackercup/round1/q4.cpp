#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
#define endl "\n";
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; ++t)
    {
        int N, M, A, B;
        cin >> N >> M >> A >> B;
        if (A < N + M - 1 || B < N + M - 1)
        {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
            continue;
        }
        vector<vi> grid(N, vector<int>(M, 1));
        grid[N - 1][M - 1] = A - (M + N - 2);
        grid[N - 1][0] = B - (M + N - 2);
        cout << "Case #" << t << ": POSSIBLE\n";
        for (auto vv : grid)
        {
            for (int i : vv)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}