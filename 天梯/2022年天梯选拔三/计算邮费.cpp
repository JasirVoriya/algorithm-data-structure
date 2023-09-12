#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    double x, y;
    cin >> x;
    if (x <= 0) {
        cout << "数据输入有误。" << endl;
        return 0;
    } else if (x > 0 && x <= 5) {
        y = 10 + x;
    } else if (x > 5 && x <= 10) {
        y = 15 + 0.5 * x;
    } else if (x > 10) {
        y = 20 + 0.3 * x;
    }
    printf("%.2lf\n", y);
    return 0;
}