#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef unsigned int ui;
const ui maxn = 2000100;
ui a[maxn];
int main(void)
{
    ull n, m;
    while (cin >> n >> m)
    {
        ull time = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            time += a[i];
        }
        double v = 1;
        while (time > m)
        {
            double n = 1.0 * time / m;
            v *= n;
            v = (int)v + (v > (int)v);
            time = 0;
            for (int i = 0; i < n; i++)
                time += a[i] / (int)v + (bool)(a[i] % (int)v);
            cout << "v: " << v << " n: " << n << " time: " << time << endl;
        }
        cout << v << endl;
    }
    return 0;
}