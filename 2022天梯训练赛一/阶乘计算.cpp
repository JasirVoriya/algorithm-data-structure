#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 2; i <= n; i++)
        ans *= i;
    cout << n << "!=" << ans << endl;
    return 0;
}