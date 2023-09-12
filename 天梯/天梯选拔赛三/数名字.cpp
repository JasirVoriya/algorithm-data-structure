#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    int ans = 1;
    string cmp1 = "predator";

    while (n--)
    {
        string str;
        cin >> str;
        if (str.size() == cmp1.size() && str.compare(cmp1.c_str()) == 0)
        {
            cout << ans << endl;
            return 0;
        }
        ans++;
    }
    return 0;
}