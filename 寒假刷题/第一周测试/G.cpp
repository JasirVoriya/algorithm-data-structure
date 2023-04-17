#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0, n, a, b;
        cin >> n;
        while (n--)
        {
            cin >> a >> b;
            ans += a * b;
        }
        cout << ans << endl;
    }

    return 0;
}