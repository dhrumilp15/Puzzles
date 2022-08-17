#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // Use first command line argument as a seed.
    srand(atoi(argv[1]));

    int n = rand() % 999 + 64;
    int d = 3;
    cout << n << " " << d << "\n";
    for (int i = 0; i < n; ++i)
    {
        cout << rand() % 999 + 2 << " ";
    }
    cout << "\n";
    cout << n / 2 << "\n";
    cout << n / 4 << "\n";
    cout << n / 8 << "\n";
    return 0;
}