#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
#define endl "\n";
#define f first;
#define s second;

int two_summer(vector<int> &nums, int k)
{
    unordered_map<int, int> num_store;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (num_store.find(nums[i]) == num_store.end())
        {
            if (num_store.find(k - nums[i]) != num_store.end())
            {
                ++count;
            }
        }
        else if (k == 2 * nums[i] && num_store[nums[i]] == 1)
        {
            ++count;
        }
        num_store[nums[i]] += 1;
    }
    return count;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    vi nums = {1, 2, 2, 3};
    cout << "two_sum: " << two_summer(nums, 6) << "\n";
    return 0;
}