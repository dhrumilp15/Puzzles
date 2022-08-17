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
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cout << "==\n";
        int n;
        cin >> n;
        vector<vi> A(n, vi(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> A[i][j];
            }
        }
        vector<vi> B(n, vi(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> B[i][j];
            }
        }
        vi R(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> R[i];
        }
        vi C(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> C[i];
        }
        bool change = true;
        while (change)
        {
            change = false;
            for (int i = 0; i < n; ++i)
            {
                int rown1s = 0;
                int neg1dx = -1;
                int wacko = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (A[i][j] == -1)
                    {
                        ++rown1s;
                        neg1dx = j;
                    } else {
                        wacko ^= A[i][j];
                    }
                }
                if (rown1s == 1)
                {
                    change = true;
                    A[i][neg1dx] = wacko ^ R[i];
                }
            }
            for (int i = 0; i < n; ++i)
            {
                int col1s = 0;
                int neg1dx = -1;
                int wacko = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (A[j][i] == -1)
                    {
                        ++col1s;
                        neg1dx = j;
                    } else {
                        wacko ^= A[j][i];
                    }
                }
                if (col1s == 1)
                {
                    change = true;
                    A[neg1dx][i] = wacko ^ C[i];
                }
            }
        }
        for (vi x : A) {
            for (int k : x) {
                cout << k << ", ";
            }
            cout << '\n';
        }

    }
    return 0;
}