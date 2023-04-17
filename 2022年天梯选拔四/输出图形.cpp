#include <bits/stdc++.h>
#define PI acos(-1)
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAX_N = 1e3;
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%-6d", i * j);
        }
        cout << endl;
    }
    return 0;
}