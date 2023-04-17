#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    int n;
    cin >> n;
    int start = 0, len = 0, m = sqrt(n);
    for (int i = 2; i <= m; i++) {
        int j = i, x = n;
        while (x % j == 0) {
            x /= j;
            j++;
        }
        if (j - i > len) {
            start = i;
            len = j - i;
        }
    }
    if (len) {
        cout << len << endl;
        cout << start;
        for (int i = 2; i <= len; i++) {
            cout << "*" << ++start;
        }
    } else
        cout << 1 << endl
             << n;
    cout << endl;
    return 0;
}