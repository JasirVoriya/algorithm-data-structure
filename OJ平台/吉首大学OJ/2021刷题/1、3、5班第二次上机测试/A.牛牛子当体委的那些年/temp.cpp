#include <bits/stdc++.h>
using namespace std;
// 输入格式
// 第一行两个个整形n、m（1<=n,m<=100），n表示需要统计n节体育课的出勤情况，m表示牛子爷班上一共有m个人。
// 接下来有n行，每行有m个A、B字符字符，表示一节体育课的出勤情况。
const int MAX_N = 100;
int main(void)
{
    ofstream cout;
    cout.open("test1.in");
    srand(time(NULL));
    int n, m;
    n = rand() % MAX_N + 1;
    m = rand() % MAX_N + 1;
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (char)('A' + rand() % 2);
        }
        cout << endl;
    }
    return 0;
}