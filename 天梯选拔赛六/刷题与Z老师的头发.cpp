#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    int ans = 0;
    int a = 0, b = 0;
    while (n--)
    {
        ans += 60;
        int q, s;
        cin >> q >> s;
        a += q, b += s;
        ans -= 20 * q;
        int x = a - b; //剩下的题
        if (x <= 0)
            ans -= 30;
        else if (2 * b < a)
            ans -= 70;
    }
    if (ans == 0)
        cout << "--";
    else if (ans < 0)
        cout << ans;
    else
        cout << "+" << ans;
    return 0;
}