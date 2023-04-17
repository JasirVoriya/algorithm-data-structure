#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    double s, n, m;
    while (cin >> s >> n >> m)
    {
        if (s == 0 && n == 0 && m == 0)
            break;
        if (n > m)
            swap(n, m);
        double mid = s / 2;
        s -= m;
        double temp = m - mid;
        if (temp / n == (int)(temp / n))
            cout << 2 * (int)(temp / n) + 1 << endl;
        else if (mid / n == (int)(mid / n))
            cout << 2 * (int)(mid / n) << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}