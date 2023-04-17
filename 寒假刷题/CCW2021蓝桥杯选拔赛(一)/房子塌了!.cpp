#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    int a;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            a = i;
    }
    cout << 2 * (a + (n / a)) << endl;
    return 0;
}