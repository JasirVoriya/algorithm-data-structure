#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 100000;
int num[maxn];
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(num, 0, sizeof(num));
        int n, x, m = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            num[x]++;
            m = max(m, num[x]);
        }
        cout << m << endl;
    }
}