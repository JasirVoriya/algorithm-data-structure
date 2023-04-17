#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6;
bool prime[MAX_N] = { true, true };
int arr[MAX_N];
int cnt = 0;
void init()
{
    for (int i = 2; i < MAX_N; i++) {
        if (prime[i] == true)
            continue;
        arr[cnt++] = i;
        for (int j = 2 * i; j < MAX_N; j += i)
            prime[j] = true;
    }
}
// 输入格式
// 第一行输入两个整形n、m（3<=n,m<=100）。
// 接下来n行，每行有m个数Xi（1<=Xi<=100），每个路径的距离。
// 然后是一行，一个整数t（1<=t<=100），表示需要查询从起点到t个终点的最短路径
// 最后是t（1<=t<=50）行，每行输入两个整形x、y（0<=x<n,0<=y<m），表示终点的坐标。
int main(void)
{
    ofstream cout;
    cout.open("test1.in");
    srand(time(NULL));
    int n, m;
    n = rand() % 98 + 3;
    m = rand() % 98 + 3;
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0, x; j < m; j++) {
            x = rand() % 100 + 1;
            cout << x << " ";
        }
        cout << endl;
    }
    int t = rand() % 50 + 1;
    cout << t << endl;
    for (int i = 0, x, y; i < t; i++) {
        x = rand() % n, y = rand() % m;
        cout << x << " " << y << endl;
    }
    return 0;
}