#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl "\n";
#define f first;
#define s second;

ull spatoi(string str)
{
    ull val = 0;
    for (char c : str)
    {
        val = val * 10 + (c - '0');
    }
    return val;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n;
        cin >> n;
        vector<ull> nums(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        ull total = 0;
        string previ = to_string(nums[0]);
        for (int i = 1; i < n; ++i)
        {
            // do nothing if nums[i] > nums[i-1]
            if (nums[i] == nums[i - 1])
            {
                nums[i] *= 10;
                total += 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                string curr = to_string(nums[i]);
                if (curr.length() == previ.length())
                {
                    nums[i] *= 10;
                    total++;
                }
                else
                { // curr.length < previ.length
                    // if there's a complete overlap
                    if (nums[i] == spatoi(previ.substr(0, curr.length())))
                    {
                        // check if you can set nums[i] to nums[i-1] + 1
                        if (previ[previ.length() - 1] != '9')
                        {
                            nums[i] = nums[i - 1] + 1;
                            total += previ.length() - curr.length();
                        }
                        else
                        {
                            nums[i] = nums[i - 1] * 10;
                            total += previ.length() - curr.length() + 1;
                        }
                    }
                    else if (nums[i] > spatoi(previ.substr(0, curr.length())))
                    {
                        nums[i] *= pow(10, previ.length() - curr.length());
                        total += previ.length() - curr.length();
                    }
                    else
                    {
                        nums[i] *= pow(10, previ.length() - curr.length() + 1);
                        total += previ.length() - curr.length() + 1;
                    }
                }
            }
            previ = to_string(nums[i]);
            // for (ll k : nums)
            // {
            //     cout << k << ", ";
            // }
            // cout << "\n";
        }
        cout << "Case #" << t << ": " << total << '\n';
    }
    return 0;
}