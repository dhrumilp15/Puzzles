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

ll find_time(int c, vector<tuple<ll, ll, ll>> &PWD)
{
    ll total = 0;
    for (auto i : PWD)
    {
        ll P = get<0>(i);
        ll W = get<1>(i);
        ll D = get<2>(i);
        if (abs(P - c) > D)
        {
            total += (abs(P - c) - D) * W;
        }
    }
    return total;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<tuple<ll, ll, ll>> PWD(n);
    for (int i = 0; i < n; ++i)
    {
        ll p, w, d;
        cin >> p >> w >> d;
        PWD[i] = make_tuple(p, w, d);
    }
    if (n == 1)
    {
        cout << get<0>(PWD[0]) << endl;
        return 0;
    }
    sort(PWD.begin(), PWD.end(), [](const auto &a, const auto &b) {
        return get<0>(a) < get<0>(b);
    });

    ll small;

    ll lower = get<0>(PWD[0]);
    ll upper = get<0>(PWD[PWD.size() - 1]);

    while (lower + 1 < upper)
    {
        ll mid = (lower + upper) / 2;
        ll midtime = find_time(mid, PWD);
        ll midtimeless = find_time(mid - 1, PWD);

        if (midtime - midtimeless == 0)
        {
            upper = midtime;
            small = min(midtime, midtimeless);
            break;
        }
        else if (midtime - midtimeless > 0)
        {
            upper = mid;
            small = min(midtime, midtimeless);
        }
        else
        {
            lower = mid;
            small = min(midtime, midtimeless);
        }
    }
    cout << small << endl;

    return 0;
}