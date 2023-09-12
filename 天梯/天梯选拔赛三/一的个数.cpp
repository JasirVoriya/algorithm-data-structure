#include <bits/stdc++.h>
using namespace std;
int fun(int n)
{
    int ans = 0;
    while (n)
    {
        ans += n & 1;
        n >>= 1;
    }
    return ans;
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << fun(i) << " ";
    return 0;
}