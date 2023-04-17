#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define mod 3777105087
int main(void)
{
    int base[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    ull n;
    while (cin >> n)
    {
        int x, y;
        cin >> x >> y;
        int times = y == 0 ? 1 : base[x];
        ull sum = 1,pre=1,res=1;
        for (int i = 2; i <= n; i++)
        {
            res = ((i * pre) % mod);
            sum = ((sum + res * times % mod) % mod);
            pre=res;
        }
        cout << sum << endl;
    }
}