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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        int lasteven = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] % 2 == 0)
            {
                if (i != lasteven)
                {
                    swap(nums[i], nums[lasteven]);
                    lasteven++;
                }
            }
        }
        sort(nums.begin(), nums.begin() + lasteven, greater<int>());
        sort(nums.begin() + lasteven, nums.end(), greater<int>());
        for (int i : nums)
        {
            cout << i << ", ";
        }
        cout << "\n";
        int bigsum = 0;
        if (lasteven)
        {
            bigsum = (lasteven * (lasteven - 1)) / 2;
        }
    }
    return 0;
}