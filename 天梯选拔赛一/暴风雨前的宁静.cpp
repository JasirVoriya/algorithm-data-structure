#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    if (n == 1 || n == 2)
        cout << 0 << endl;
    else if (n == 3)
        cout << "2\n1 3" << endl;
    else if (n == 4)
        cout << "3\n4 1 3" << endl;
    else
    {
        cout << n << endl;
        for (int i = 1; i <= n; i += 2)
            cout << i << " ";
        for (int i = 2; i <= n; i += 2)
            cout << i << " ";
    }
    return 0;
}