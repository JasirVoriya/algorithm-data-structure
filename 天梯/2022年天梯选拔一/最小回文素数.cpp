#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 65535 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
// 给定一个非负整数n，寻找比它大的最小回文素数。例如，当n=100时，结果为101。因为101是回文数（正读、反读都一样的数）且是素数。
bool check(int n)
{
    int x = 0, y = n;
    while (n) {
        x = x * 10 + n % 10;
        n /= 10;
    }
    return x == y;
}
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (n++; true; n++) {
            if (check(n) && isPrime(n)) {
                cout << n << endl;
                break;
            }
        }
    }
    return 0;
}