#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    const string account = "12345", psw = "567890";
    double limit = 20000;
    string acc, ps;
    double x, y;
    cin >> acc >> ps >> x >> y;
    if (!(acc == account && ps == psw)) {
        cout << "帐号或密码错误" << endl;
        return 0;
    }
    if (y > x) {
        cout << "余额不足" << endl;
        return 0;
    }
    if (y > limit) {
        cout << "超过单次取款限额" << endl;
        return 0;
    }
    printf("取款成功:%.2lf-%.2lf=%.2lf\n", x, y, x - y);
    return 0;
}