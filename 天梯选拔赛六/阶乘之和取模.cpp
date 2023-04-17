#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6;
int main(void)
{
    int sum = 1, x = 1;
    int n;
    cin >> n;
    if (n > mod)
        n = mod;
    for (int i = 2; i <= n; i++)
    {
        x = (x * i) % mod;
        sum = (sum + x) % mod;
    }
    cout << sum;
    return 0;
}