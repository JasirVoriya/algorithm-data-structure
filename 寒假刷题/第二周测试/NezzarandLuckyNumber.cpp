#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        ull q, d, a;
        cin >> q >> d;
        for (int i = 0; i < q; i++)
        {
            scanf("%llu", &a);
            if (a % d == 0)
                cout << "YES" << endl;
            else
            {
                ull x = a / d, y = a % d;
                int count = 0;
                if (a > 10 * d)
                {
                    cout << "YES" << endl;
                    continue;
                }
                while (y % 10 && count < x)
                {
                    y += d;
                    count++;
                }
                if (count < x)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}