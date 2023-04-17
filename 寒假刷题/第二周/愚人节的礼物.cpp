#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string str;
    while (cin >> str) {
        int ans = str.find('B');
        ans -= 2 * count(str.begin(), str.begin() + ans, ')');
        cout << ans << endl;
    }
    return 0;
}