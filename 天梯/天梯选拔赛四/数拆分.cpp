#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e6 + 5;
const int mod = 1000000000;

int fun(int x)
{
    if (x == 1)
        return 0;
    return 2 * fun(x / 2) + 1;
}
int solove(int n)
{
    int base = 1;
    int ans = 0;
    while (n)
    {
        if (n & 1)
            ans = (ans + fun(base) + 1) % mod;
        base <<= 1;
        n >>= 1;
    }
    return ans;
}
int main(void)
{
    for (int i = 1; i < 100; i++)
        cout << i << " " << solove(i) << endl;
    return 0;
}