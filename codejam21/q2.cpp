#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl "\n";
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int X, Y;
        string mural;
        cin >> X >> Y >> mural;
        int last = 0;
        for (int i = 0; i < mural.length(); ++i)
        {
            if (mural[i] == '?')
                continue;
            last = i;
            if (i > 0)
            {
                mural[i - 1] = mural[i];
            }
            break;
        }
        last = max(last, 1);

        for (int i = last; i < mural.length() - 1; ++i)
        {
            if (mural[i] != '?')
                continue;
            if (mural[i - 1] == 'C')
            {
                if (mural[i + 1] == 'J')
                {
                    if (Y)
                    {
                        mural[i] = 'C';
                    }
                    else
                    {
                        mural[i] = 'J';
                    }
                }
                else
                {
                    mural[i] = 'C';
                }
            }
            else if (mural[i - 1] == 'J')
            {
                if (mural[i + 1] == 'C')
                {
                    if (X)
                    {
                        mural[i] = 'J';
                    }
                    else
                    {
                        mural[i] = 'C';
                    }
                }
                else
                {
                    mural[i] = 'J';
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < mural.length() - 1; ++i)
        {
            if (mural[i] == 'C' && mural[i + 1] == 'J')
            {
                sum += X;
            }
            if (mural[i] == 'J' && mural[i + 1] == 'C')
            {
                sum += Y;
            }
        }
        cout << "Case #" << t << ": " << sum << "\n";
    }
    return 0;
}