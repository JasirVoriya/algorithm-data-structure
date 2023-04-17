#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int b[maxn];
bool cmp(int a, int b)
{
    return a > b;
}
int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        for (int i = 0, j = l - 1; j < r; j++, i++)
            b[i] = a[j];
        sort(b, b + (r - l + 1), cmp);
        cout << b[k - 1] << endl;
    }
    return 0;
}