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
    int N;
    cin >> N;
    vector<ll> nums;
    for (int i = 0; i < N; ++i)
    {
        ll k;
        cin >> k;
        nums.push_back(k);
    }
    // dumb solution
    ll maxnum = LONG_LONG_MIN;
    int maxy = -1;
    for (int i = 0; i < N; ++i)
    {
        if (nums[i] > maxnum) // we'll grab the earliest max
        {
            maxnum = nums[i];
            maxy = i;
        }
    }
    ll total = 0;
    ll rprev = LONG_LONG_MIN;
    for (int i = 0; i < maxy; ++i)
    {
        if (nums[i] < rprev)
        {
            total += rprev - nums[i];
            nums[i] = rprev;
        }
        rprev = nums[i];
    }
    ll rrprev = LONG_LONG_MIN;
    for (int i = N - 1; i > maxy; --i)
    {
        if (nums[i] < rrprev)
        {
            total += rrprev - nums[i];
            nums[i] = rrprev;
        }
        rrprev = nums[i];
    }
    // cout << "nums: ";
    // for (int i : nums)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    cout << total << endl;

    return 0;
}