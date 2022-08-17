#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
#define endl "\n";

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        int n;
        cin >> n;
        vector<int> arr;
        int ones = 0;
        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            arr.push_back(num);
            if (num == 1)
                ones++;
        }
        int zeros = n - ones;

        if (ones <= n / 2)
        {
            cout << n - ones << endl;
            for (int i = 0; i < n - ones; ++i)
            {
                cout << 0 << " ";
            }
        }
        else
        {
            // THERE ARE FEWER THAN N/2 0's
            if (ones % 2 == 0)
            {
                cout << ones << endl;
                for (int i = 0; i < ones; ++i)
                {
                    cout << 1 << " ";
                }
            }
            else
            {
                cout << ones - 1 << endl;
                for (int i = 0; i < ones - 1; ++i)
                {
                    cout << 1 << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}