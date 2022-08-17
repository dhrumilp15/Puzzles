#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long count = 0;
    string word;
    cin >> word;
    for (char &c : word)
    {
        if (c == '0')
            count++;
    }
    cout << count << endl;
    cout << max(((count) * (count - 1)) / 2, (long)0) << endl;
    return 0;
}
