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

int find_min_hydrants(vi &houses, int &hose)
{
    vi ans;
    int stretcher = hose * 2;
    int i = 0;
    int best = houses.size();
    while (i < houses.size() && houses[i] <= houses[0] + stretcher)
    {
        int hoses_needed = 1;
        int curr = houses[i];
        int j = i + 1;
        while (j < houses.size() && houses[i] > (houses[j] + stretcher - 1000000))
        {
            if (houses[j] > curr)
            {
                hoses_needed++;
                curr = houses[j] + stretcher;
            }
            j++;
        }
        best = min(best, hoses_needed);
        i++;
    }
    return best;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vi houses(n);
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        houses[i] = k;
    }
    int hydrants;
    cin >> hydrants;
    if (hydrants >= n)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(houses.begin(), houses.end());

    int lower = -1;
    int upper = 1000000;

    while (lower + 1 < upper)
    {
        int mid = (upper + lower) / 2;
        if (hydrants < find_min_hydrants(houses, mid))
        {
            lower = mid;
        }
        else
        {
            upper = mid;
        }
    }
    cout << upper << endl;

    return 0;
}