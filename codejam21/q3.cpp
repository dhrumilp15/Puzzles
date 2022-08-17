#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl "\n";
#define f first;
#define s second;

int checker(int N, vi vec)
{
    // int N;
    // cin >> N;
    // vi vec(N, 0);
    // for (int i = 0; i < N; ++i)
    // {
    //     cin >> vec[i];
    // }
    int cost = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        int mindex = -1;
        int minval = INT_MAX;
        for (int j = i; j < N; ++j)
        {
            minval = min(minval, vec[j]);
            if (minval == vec[j])
            {
                mindex = j;
            }
        }
        reverse(vec.begin() + i, vec.begin() + mindex + 1);
        cost += mindex - i + 1;
    }
    return cost;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int N, C;
        cin >> N >> C;
        if (C < N - 1 || C >= (N * (N + 1)) / 2)
        {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
            continue;
        }
        vi ans(N, 0);
        for (int i = 1; i < N + 1; ++i)
        {
            ans[i - 1] = i;
        }
        int i = N - 2;
        C -= N - 1;
        while (C > 0)
        {
            if (C >= N - i)
            {
                reverse(ans.begin() + i, ans.begin() + N);
            }
            else
            {
                reverse(ans.begin(), ans.begin() + C + 1);
            }
            C -= N - i - 1;
            i--;
        }
        cout << "Case #" << t << ": ";
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}