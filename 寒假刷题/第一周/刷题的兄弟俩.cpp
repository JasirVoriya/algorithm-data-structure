#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n % (m + 1))
            cout << "lbg" << endl;
        else
            cout << "gbl" << endl;
    }
    return 0;
}