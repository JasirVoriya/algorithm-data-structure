#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
int a[MAX_N], b[MAX_N];
bool cmp(int a, int b)
{
    return a > b;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, cmp);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(b, b + n, cmp);
        //
        int ans = 0;
        for (int i = 0, index = 0; i < n && index < n; i++, index++)
        {
            while (index < n && b[i] <= a[index])
                index++;
            if (index < n)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}