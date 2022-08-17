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
    int t;
    cin >> t;
    while (t--)
    {
        int k, n, m;
        cin >> k >> n >> m;
        string b;
        getline(cin, b);
        vector<int> mono(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> mono[i];
        }
        vector<int> poly(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> poly[i];
        }
        int monoptr = 0;
        int polyptr = 0;
        int filelength = k;
        vector<int> actions;
        while (monoptr < n && polyptr < m)
        {
            // cout << "filelength: " << filelength << "\n";
            if (mono[monoptr] <= filelength || poly[polyptr] <= filelength)
            {
                if (mono[monoptr] <= filelength)
                {
                    actions.push_back(mono[monoptr]);
                    if (mono[monoptr] == 0)
                    {
                        ++filelength;
                    }
                    ++monoptr;
                }
                if (poly[polyptr] <= filelength)
                {
                    actions.push_back(poly[polyptr]);
                    if (poly[polyptr] == 0)
                    {
                        ++filelength;
                    }
                    ++polyptr;
                }
            }
            else
            {
                break;
            }
        }
        while (monoptr < n)
        {
            // cout << "filelength: " << filelength << "\n";
            if (mono[monoptr] <= filelength)
            {
                actions.push_back(mono[monoptr]);
                if (mono[monoptr] == 0)
                {
                    ++filelength;
                }
                ++monoptr;
            }
            else
            {
                break;
            }
        }
        while (polyptr < m)
        {
            // cout << "filelength: " << filelength << "\n";
            if (poly[polyptr] <= filelength)
            {
                actions.push_back(poly[polyptr]);
                if (poly[polyptr] == 0)
                {
                    ++filelength;
                }
                ++polyptr;
            }
            else
            {
                break;
            }
        }
        // cout << "n: " << n << ", m: " << m << "\n";
        // cout << "monoptr: " << monoptr << ", polyptr: " << polyptr << "\n";
        if (monoptr != n || polyptr != m)
        {
            cout << -1 << "\n";
            continue;
        }
        for (int &i : actions)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}