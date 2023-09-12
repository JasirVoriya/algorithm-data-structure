#include <bits/stdc++.h>
using namespace std;
int a[1100];
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i = 0, j = 0, k = 0;
        cin >> a[0];
        int x = 0;
        while (++x < n)
        {
            cin >> a[x];
            if (a[x] <= a[i])
                i = x;
            else
            {
                j = x;
                break;
            }
        }
        if (j != 0)
            while (++x < n)
            {
                cin >> a[x];
                if (a[x] >= a[j])
                    j = x;
                else
                {
                    k = x;
                    break;
                }
            }
        while (++x < n)
            cin >> a[x];
        if (k != 0)
        {
            cout << "YES" << endl;
            cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
        }
        else
            cout << "NO" << endl;
    }
}