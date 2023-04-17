#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
const ull maxn = 110;
const ull mod = 1e9 + 7;
ull ans[maxn][maxn];
ull pro[maxn];
void init()
{
    pro[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        pro[i] = (pro[i - 1] * i) % mod;
        ans[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            ans[i][j] = (pro[i] / ((pro[j] * pro[i - j]) % mod)) % mod;
        }
    }
}
int main(void)
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << ans[n][m] << endl;
    }

    return 0;
}