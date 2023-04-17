#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    int book[110] = {0};
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> book[i];
        if (n <= m)
        {
            cout << 100 << endl;
            continue;
        }
        book[n + 1] = 101;
        int ans = 0;
        for (int i = 0; i + m + 1 <= n + 1; i++)
            ans = max(ans, book[i + m + 1] - book[i] - 1);
        cout << ans << endl;
    }
    return 0;
}