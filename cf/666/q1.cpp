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
    for (int i = 0; i < N; ++i)
    {
        int W;
        cin >> W;
        vector<string> words;
        unordered_map<char, int> counter;
        for (int j = 0; j < W; ++j)
        {
            string word;
            cin >> word;
            words.push_back(word);
            for (auto &c : word)
            {
                if (counter.find(c) != counter.end())
                {
                    ++counter[c];
                }
                else
                {
                    counter[c] = 1;
                }
            }
        }
        bool flag = true;
        for (auto it = counter.begin(); it != counter.end(); ++it)
        {
            if (it->second % W != 0)
            {
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
    }
    return 0;
}