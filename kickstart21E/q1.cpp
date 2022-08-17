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
    int n;
    cin >> n;
    for (int tt = 1; tt <= n; ++tt)
    {
        string word;
        cin >> word;
        int n = word.size();
        map<char, int> letters;
        for (int i = 0; i < n; ++i)
        {
            ++letters[word[i]];
        }
        int biggest = -1;

        bool flag = false;

        for (auto it : letters)
        {
            if (it.second > n - it.second)
            {
                flag = true;
                break;
            }
            biggest = max(biggest, it.second);
        }
        if (flag)
        {
            cout << "Case #" << tt << ": IMPOSSIBLE\n";
            continue;
        }

        vector<pair<char, int>> sussywussy;
        for (int i = 0; i < word.size(); ++i)
        {
            sussywussy.push_back(make_pair(word[i], i));
        }
        sort(sussywussy.begin(), sussywussy.end(), [](const auto &a, const auto &b)
             { return a.first < b.first; });

        vector<char> newword(n);
        for (int i = 0; i < n; ++i)
        {
            newword[sussywussy[i].second] = sussywussy[(i - biggest + word.size()) % word.size()].first;
        }
        string sussy;
        for (char c : newword)
        {
            sussy += c;
        }
        cout << "Case #" << tt << ": " << sussy << "\n";
    }
    return 0;
}