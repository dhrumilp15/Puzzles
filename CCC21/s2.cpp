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

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int M;
    cin >> M;
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<bool> rows(M, 0);
    vector<bool> cols(N, 0);
    // 0 for black
    for (int i = 0; i < K; ++i)
    {
        char c;
        cin >> c;
        int num;
        cin >> num;
        if (c == 'R')
        {
            rows[num - 1] = rows[num - 1] ^ 1;
        }
        else
        {
            cols[num - 1] = cols[num - 1] ^ 1;
        }
    }
    // cout << " ";
    // for (bool c : cols)
    // {
    //     cout << c << " ";
    // }
    // cout << endl;
    // for (bool c : rows)
    // {
    //     cout << c << endl;
    // }
    // cout << endl;
    ll colblacks = 0;
    ll colwhites = 0;
    for (bool i : cols)
    {
        if (i)
        {
            colwhites++;
        }
        else
        {
            colblacks++;
        }
    }
    ll rowblacks = 0;
    ll rowwhites = 0;
    for (bool i : rows)
    {
        if (i)
        {
            rowwhites++;
        }
        else
        {
            rowblacks++;
        }
    }
    cout << rowblacks * colwhites + rowwhites * colblacks << endl;

    return 0;
}