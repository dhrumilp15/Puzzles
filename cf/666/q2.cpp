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
    int N;
    cin >> N;
    vector<int> nums;
    for (int i = 0; i < N; ++i)
    {
        int newnum;
        cin >> newnum;
        nums.push_back(newnum);
    }
    sort(nums.begin(), nums.end());
    long mintcost = LONG_MAX;
    //assume the value closest to the value for the end element
    long lastcost = mintcost;
    for (int c = 1; c < 31624; ++c)
    {
        long tcost = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            tcost += abs(nums.at(i) - pow(c, i));
        }
        mintcost = min(mintcost, tcost);
        if (mintcost != tcost)
        {
            break;
        }
    }
    cout << mintcost << endl;
    return 0;
}