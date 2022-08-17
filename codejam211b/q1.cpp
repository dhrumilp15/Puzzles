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
// #define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        vector<dbl> times(3, 0);
        for (int i = 0; i < 3; ++i)
        {
            cin >> times[i];
        }

        for (int h = 0; h < 3; ++h)
        {
            for (int m = 0; m < 3; ++m)
            {
                if (m == h)
                    continue;
                for (int s = 0; s < 3; ++s)
                {
                    if (s == h || s == m)
                        continue;
                    double hours = times[h];
                    double mins = times[m];
                    double sec = times[s];
                    hours /= (12.0 * pow(10, 10));
                    mins /= (12.0 * pow(10, 10));
                    sec /= (12.0 * pow(10, 10));

                    dbl minsfrommins = mins / 6.0;
                    dbl secsfrommin = (minsfrommins - (int)minsfrommins) * 60.0;

                    dbl minsfromhour = (hours / 30.0 - (int)(hours / 30.0)) * 60.0;
                    dbl secsfromhour = (minsfromhour - ((int)minsfromhour)) * 60.0;
                    cout << "hour: " << minsfromhour << " " << secsfromhour << "\n";
                    cout << "min: " << minsfrommins << " " << secsfrommin << "\n";
                    if ((ll)minsfromhour == (ll)minsfrommins)
                    {
                        cout << "mins";
                    }
                    if ((ll)secsfromhour == (ll)(sec / 6.0))
                    {
                        cout << "sec";
                    }
                    if ((ll)secsfrommin == (ll)secsfromhour)
                    {
                        cout << "secs";
                    }

                    // if (!(minsfrommins == minsfromhour && secsfrommin == sec / 6.0 && secsfrommin == secsfromhour))
                    // {
                    //     continue;
                    // }

                    cout
                        << (hours / 30.0) << " " << mins / 6.0 << " " << sec / 6.0 << "\n";
                    cout << "=====\n";
                }
            }
        }
        times.clear();
        cout << t << "==\n";
    }
    return 0;
}