// Hard problem from codesignal intervieww, smth like find the number of
// pairs where number B + the reverse of number A = number A + the reverse of number B
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
#define endl "\n";
#define f first;
#define s second;

long long nChoosek(int n, int k)
{
    if (k > n)
        return 0;
    if (k * 2 > n)
        k = n - k;
    if (k == 0)
        return 1;

    long long result = n;
    for (int i = 2; i <= k; ++i)
    {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t; // Number of tests
    for (int tt = 0; tt < t; ++tt)
    {
        int N; // Number of numbers in the list
        cin >> N;
        vector<int> num;
        for (int i = 0; i < N; ++i)
        {
            int k;
            cin >> k;
            num.push_back(k);
        }

        for (int i = 0; i < N; ++i)
        {
            int val = 0;
            int count = 0;
            int temp = num[i];
            while (temp != 0)
            {
                val += temp % 10;
                count++;
                temp /= 10;
            }
            temp = num[i];
            for (int i = 0; i < ceil((float)(count) / 2.0); ++i)
            {
                if (count != 1)
                {
                    val -= 2 * temp % 10;
                }
                else
                {
                    val -= temp % 10;
                }
                temp /= 10;
            }
            num[i] = val;
        }
        cout << "num: ";
        for (int i : num)
        {
            cout << i << ", ";
        }
        cout << "\n";

        unordered_map<int, int> Jmap;

        for (int i : num)
        {
            Jmap[i]++;
        }
        int sickomode = 0;
        cout << "Jmap: ";
        for (auto it : Jmap)
        {
            cout << "(" << it.first << " : " << it.second << "), ";
            cout << "Added " << nChoosek(it.second, 2) << endl;
            sickomode += nChoosek(it.second, 2);
        }
        cout << sickomode + num.size() << endl;
    }
    return 0;
}