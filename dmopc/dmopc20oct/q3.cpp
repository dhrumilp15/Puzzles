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
    ll N;
    cin >> N;
    vector<ll> nums;
    for (ll i = 0; i < N; ++i)
    {
        ll k;
        cin >> k;
        nums.push_back(k);
    }
    vector<ll> lpp(N, 0);
    vector<ll> lcost(N, 0);
    lpp[N - 1] = nums[N - 1];

    for (ll i = N - 2; i >= 0; --i)
    {
        if (nums[i] < lpp[i + 1])
        {
            lcost[i] = lpp[i + 1] - nums[i];
            lpp[i] = lpp[i + 1];
        }
        else
        {
            lpp[i] = nums[i];
        }
    }
    for (ll i = N - 2; i >= 0; --i)
    {
        lcost[i] += lcost[i + 1];
    }
    vector<ll> rpp(N, 0);
    vector<ll> rcost(N, 0);
    rpp[0] = nums[0];

    for (ll i = 1; i < N; ++i)
    {
        if (nums[i] < rpp[i - 1])
        {
            rcost[i] = rpp[i - 1] - nums[i];
            rpp[i] = rpp[i - 1];
        }
        else
        {
            rpp[i] = nums[i];
        }
    }
    for (ll i = 1; i < N; ++i)
    {
        rcost[i] += rcost[i - 1];
    }
    ll total = INT_MAX;

    for (ll i = 0; i < N; ++i)
    {
        ll tot = lcost[i] + rcost[i] - min(lcost[i], rcost[i]); // cumulative cost to become the pivot for the left side
        // (this INCLUDES incrementing nums[i] to satisfy the increment from the right)
        total = min(total, tot);
    }
    cout << total << endl;
    // cout << "nums:  ";
    // for (int i : nums)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "lcost: ";
    // for (int i : lcost)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "lpp: ";
    // for (int i : lpp)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "rcost: ";
    // for (int i : rcost)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "rpp: ";
    // for (int i : rpp)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << total << endl;

    return 0;
}