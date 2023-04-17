#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            cout << 0 << endl;
        else if (2 * n == 3 * m)
            cout << 2 * n + 2 << endl;
        else if (2 * n > 3 * m)
            cout << 2 * n << endl;
        else
            cout << 3 * m << endl;
    }
    return 0;
}