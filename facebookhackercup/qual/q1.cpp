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

bool isvow(char &letter)
{
    return letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U';
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt)
    {
        int vowels = 0;
        int consonants = 0;
        unordered_map<char, int> cons;
        unordered_map<char, int> vows;

        string word;
        cin >> word;
        int max_cons = -1;
        int max_vows = -1;
        for (char letter : word)
        {
            if (isvow(letter))
            {
                ++vows[letter];
                max_vows = max(max_vows, vows[letter]);
                ++vowels;
            }
            else
            {
                ++cons[letter];
                max_cons = max(max_cons, cons[letter]);
                ++consonants;
            }
        }
        // for (auto it : vows)
        // {
        //     cout << it.first << ": " << it.second << ", ";
        // }
        // cout << "\n";
        // for (auto it : cons)
        // {
        //     cout << it.first << ": " << it.second << ", ";
        // }
        // cout << "\n";
        int ans = min(consonants + (vowels - max_vows) * 2, vowels + (consonants - max_cons) * 2);
        if (cons.empty() && vows.size() > 1)
        {
            ans = vowels;
        }
        else if (vows.empty() && cons.size() > 1)
        {
            ans = consonants;
        }

        cout << "Case #" << tt << ": " << ans << "\n";
    }
    return 0;
}