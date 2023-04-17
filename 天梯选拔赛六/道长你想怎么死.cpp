#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull maxn = 35;
ull ans[maxn] = {1, 1, 2, 4};
void init()
{
    for (ull i = 4; i < maxn; i++)
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
}
int main(void)
{
    init();
    // for (int i = 1; i <= 30; i++)
    //     cout << ans[i] << endl;
    ull n;
    while (cin >> n)
        cout << ans[n] << endl;
    return 0;
}