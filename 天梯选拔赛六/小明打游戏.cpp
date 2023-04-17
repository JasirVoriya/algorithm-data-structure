#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int val[maxn], presum[maxn];
int n;
void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        presum[i] = presum[i - 1] + val[i];
    }
}
int Sum(int x, int y)
{
    return presum[y] - presum[x - 1];
}
int solove()
{
    init();
    int ans = 0;
    for (int len = 1; len <= n; len++)
    {
        for (int x = 1, v; x + len - 1 <= n; x++)
        {
            v = Sum(x, x + len - 1);
            ans = ans > v ? ans : v;
        }
    }
    return ans;
}
int main(void)
{
    cout << solove();
    return 0;
}