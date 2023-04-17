#include <bits/stdc++.h>
using namespace std;
bool fun(int x, int y)
{
    if (x == y)
        return true;
    if (x <= 3)
        return false;
    return true;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (fun(x, y))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}