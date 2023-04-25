#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int maxn = 1e4 + 5;
int check(int x, int y) {
    int i = y;
    while (x % i == 0) x /= i, i++;
    return i - y;
}
int main(void) {
    int n;
    ifstream cin("data.in");
    ofstream cout("data1.out");
    while (cin >> n) {
        int x = sqrt(n);
        PII s(1, n);
        for (int i = 2; i <= x; i++) {
            if (n % i == 0) {
                int l = check(n, i);
                // cout << i << ":" << l << endl;
                if (l == 1 && i < s.second) s = PII(l, i);
                if (l > s.first) s = PII(l, i);
                i += l - 1;
                continue;
            }
            // cout << i << ":0" << endl;
        }
        cout << n << endl;
        cout << s.second;
        for (int i = 1; i < s.first; i++) {
            cout << "*" << s.second + i;
        }
        cout << endl;
    }
    return 0;
}