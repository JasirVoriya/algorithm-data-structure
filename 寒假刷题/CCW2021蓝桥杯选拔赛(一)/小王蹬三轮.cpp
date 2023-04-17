#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int x[maxn];
void updata(int a, int b)
{
    x[a]++, x[b + 1]--;
}
int main(void)
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        memset(x, 0, sizeof(x));
        int a, b;
        for (int i = 1; i <= n; i++)
        {
            cin >> a >> b;
            updata(a, b);
        }
        int ans = x[1];
        cout << ans;
        for (int i = 2; i <= n; i++)
        {
            ans += x[i];
            cout << ' ' << ans;
        }
        cout << endl;
    }
    return 0;
}