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

int F(string &word)
{
    char currgroup;
    for (char letter : word)
    {
        if (letter != 'F')
        {
            currgroup = letter;
            break;
        }
    }
    int res = 0;
    for (char letter : word)
    {
        if (letter != 'F')
        {
            if (letter != currgroup)
            {
                ++res;
                currgroup = letter;
            }
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int tt;
    cin >> tt;
    int oniichan = 1e9 + 7;
    for (int t = 1; t <= tt; ++t)
    {
        int n;
        cin >> n;
        string inp;
        cin >> inp;
        string word;
        for (char letter : inp)
        {
            if (letter == '.')
            {
                word += word;
            }
            else
            {
                word += letter;
            }
        }
        vector<ll> dp(word.size());
        // bottom left half is the same by symmetry
        char currgroup;
        for (char letter : word)
        {
            if (letter != 'F')
            {
                currgroup = letter;
                break;
            }
        }

        for (int j = 1; j < word.size(); ++j)
        {
            if (word[j] == 'F')
            {
                dp[j] = dp[j - 1];
            }
            else
            {
                if (currgroup == word[j])
                {
                    dp[j] = dp[j - 1];
                }
                else
                {
                    dp[j] = dp[j - 1] + 1;
                    currgroup = word[j];
                }
            }
        }
        if (dp[word.size() - 1] == 0)
        {
            cout << "Case #" << t << ": 0\n";
            continue;
        }

        for (char letter : word)
        {
            if (letter != 'F')
            {
                currgroup = letter;
                break;
            }
        }

        vector<int> last;
        int lastval = 0;
        for (int i = 0; i < word.size(); ++i)
        {
            if (word[i] != 'F')
            {
                if (word[i] != currgroup)
                {
                    last.push_back(lastval);
                    currgroup = word[i];
                }
                lastval = i + 1;
            }
        }
        vector<ll> prefix(word.size());
        prefix[0] = dp[0];
        for (int i = 1; i < word.size(); ++i)
        {
            prefix[i] += dp[i] + prefix[i - 1];
        }

        // cout << "last: ";
        // for (int i : last)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // cout << "dp: ";
        // for (int i : dp)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";

        // cout << "prefix: ";
        // for (int i : prefix)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";

        int val = 0;
        int index = 0;
        int lastindex = 1;
        ll wordsize = word.size();
        ll ans = (prefix[wordsize - 1] * last[0]) % oniichan;
        // cout << "initial ans: " << ans << "\n";

        for (int lindex = 1; lindex < last.size(); ++lindex)
        {
            // cout << "lastval: " << last[lindex] << "\n";
            int dpindex = last[lindex];
            if (word[last[lindex]] != 'F')
            {
                --dpindex;
            }
            // cout << "dp val: " << dp[dpindex] << "\n";
            // cout << prefix[wordsize - 1] << "-" << prefix[dpindex] << "-" << (dp[dpindex] * (wordsize - dpindex - 1)) << ")*(" << last[lindex] << "-" << last[lindex - 1] << "=";
            // cout << (prefix[wordsize - 1] - prefix[dpindex] - (dp[dpindex] * (wordsize - dpindex - 1))) * (last[lindex] - last[lindex - 1]) << "\n";
            ans = (ans % oniichan + (prefix[wordsize - 1] - prefix[dpindex] - (dp[dpindex] * (wordsize - dpindex - 1))) * (last[lindex] - last[lindex - 1]) % oniichan) % oniichan;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}