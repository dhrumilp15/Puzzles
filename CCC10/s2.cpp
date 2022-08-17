#include <bits/stdc++.h>

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
    int n;
    cin >> n;
    unordered_map<string, char> mapper;
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        string k;
        cin >> k;
        mapper.emplace(make_pair(k, c));
    }
    string code;
    cin >> code;
    string ans;
    int bufindex = 0;
    for (int i = 0; i < code.length(); ++i)
    {
        string subs = code.substr(bufindex, i - bufindex + 1);
        if (mapper.find(subs) != mapper.end())
        {
            ans += mapper.find(subs)->second;
            bufindex = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}