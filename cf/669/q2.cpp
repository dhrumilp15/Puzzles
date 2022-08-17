#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
#define endl "\n";

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int tests = 0; tests < t; ++tests)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            a.push_back(num);
        }
        vector<int> b;
        int maxx = INT_MIN;
        int maxposs = -1;
        vector<bool> pos(n, true);
        for (int i = 0; i < n; ++i)
        {
            maxx = max(maxx, a.at(i));
            if (maxx == a.at(i))
            {
                maxposs = i;
            }
        }
        b.push_back(maxx);
        pos[maxposs] = false;
        int gcpos = maxx;

        for (int j = 0; j < n - 1; ++j)
        {
            int trygcd = -1;
            int maxpos = -1;
            for (int i = 0; i < n; ++i)
            {
                if (pos.at(i))
                {
                    int thisgcd = gcd(gcpos, a.at(i));
                    if (thisgcd > trygcd)
                    {
                        maxpos = i;
                        trygcd = thisgcd;
                    }
                }
            }
            pos[maxpos] = false;
            b.push_back(a.at(maxpos));
            gcpos = trygcd;
        }
        for (int i : b)
        {
            cout << i << " ";
        }
        cout << endl;
        
    }
    return 0;
}