// 问题 A: 牛子爷快跑！
// 描述
// 牛子爷又在实验室偷偷内卷，反卷大队WXM和TQ破门而入，准备将牛子爷擒拿归案。
// 牛牛子疯狂逃跑，由于地形非常复杂，牛子爷不知道哪个才是真正的出口，而且只能向右或者向下走，所以牛子爷打算把所有的地方全都走一遍。
// 请你帮牛子爷计算出从起点(0,0)开始，到所有地方的最短距离。
// 
// 格式
// 输入格式
// 第一行输入两个整形n、m（3<=n,m<=100）。
// 接下来n行，每行有m个数Xi（1<=Xi<=100），每个路径的距离。
// 然后是一行，一个整数t（1<=t<=100），表示需要查询从起点到t个终点的最短路径
// 最后是t（1<=t<=50）行，每行输入两个整形x、y（0<=x<n,0<=y<m），表示终点的坐标。
// 
// 输出格式
// 一共有t行，分别输出起点到对应终点的最短路径。
// 
// 样例
// 样例输入 Copy
// 3 3
// 1 3 1
// 1 5 1
// 4 2 1
// 1
// 2 2
// 样例输出 Copy
//7
// 
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int main(void)
{
    ifstream cin;
    ofstream cout;
    cin.open("test1.in");
    cout.open("test1.out");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for (int i = 1; i < m; i++)
        dp[0][i] = dp[0][i - 1] + arr[0][i];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + arr[i][0];
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
        }
    }
    int t;
    cin >> t;
    for (int i = 0, x, y; i < t; i++) {
        cin >> x >> y;
        cout << dp[x][y] << endl;
    }
    return 0;
}