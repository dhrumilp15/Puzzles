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
    int t;
    cin >> t;
    while (t--)
    {
        string word;
        cin >> word;
        // cout << word << "\n";
        if (word.length() == 1)
        {
            if (word[0] == 'a')
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            continue;
        }
        int letter = word.length() - 1;
        int left = 0;
        int right = word.length() - 1;

        while (left != right)
        {
            if (word[left] == letter + 'a' || word[right] == letter + 'a')
            {
                if (word[left] == letter + 'a')
                {
                    ++left;
                    --letter;
                }
                else
                {
                    --right;
                    --letter;
                }
            }
            else
            {
                break;
            }
        }
        if (left == right && word[left] == 'a')
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        //     if (word.length() > 2)
        //     {
        //         queue<int> apos;
        //         vector<bool> seen(word.length());
        //         for (int i = 0; i < word.length(); ++i)
        //         {
        //             if (word[i] == 'a')
        //             {
        //                 apos.push(i);
        //                 break;
        //             }
        //         }
        //         while (!apos.empty() && yes)
        //         {
        //             int letter = apos.front();
        //             apos.pop();
        //             bool left = false;
        //             bool right = false;
        //             if (letter > 0)
        //             {
        //                 if (!seen[letter - 1])
        //                 {
        //                     if (word[letter - 1] - 'a' == word[letter] - 'a' + 1)
        //                     {
        //                         left = true;
        //                     }
        //                     apos.push(letter - 1);
        //                 }
        //             }
        //             if (letter < word.size() - 1)
        //             {
        //                 if (!seen[letter + 1])
        //                 {
        //                     if (word[letter + 1] - 'a' == word[letter] - 'a' + 1)
        //                     {
        //                         right = true;
        //                     }
        //                     apos.push(letter + 1);
        //                 }
        //             }
        //             if (!(left || right))
        //             {
        //                 yes = false;
        //             }
        //             seen[letter] = true;
        //         }
        //     }

        //     for (int i = 0; i < word.length() && yes; ++i)
        //     {
        //         if (lowercase[i] != 1)
        //         {
        //             yes = false;
        //         }
        //     }
        //     if (yes)
        //     {
        //         cout << "YES\n";
        //     }
        //     else
        //     {
        //         cout << "NO\n";
        //     }
    }
    return 0;
}