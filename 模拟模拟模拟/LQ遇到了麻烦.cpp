#include <bits/stdc++.h>
using namespace std;
const int maxn=1000;
char M[maxn][maxn];
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 1; i < maxn; i++)
            for (int j = 1; j < maxn; j++)
                M[i][j] = '*';
        int a, b, c;
        cin >> a >> b >> c;
        int point1 = 3 + 2 * (b - 1), point2 = point1, point3 = point1 + 2 * a;
        //打印顶面
        for (int x = 1, y = point1; x <= point2; x += 2, y -= 2)
        {
            //奇数行
            int dx = x, dy = y;
            M[dx][dy++] = '+';
            for (int i = 1; i <= a; i++)
                M[dx][dy++] = '-', M[dx][dy++] = '+';
            //偶数行
            dx = x + 1, dy = y - 1;
            M[dx][dy++] = '/';
            if (dx > point2)
                break;
            for (int i = 1; i <= a; i++)
                M[dx][dy++] = '*', M[dx][dy++] = '/';
        }
        //打印正面
        for (int i = 1; i <= c; i++)
        {
            //奇数行
            int x = point2 + 1 + 2 * (i - 1), y = 1;
            M[x][y++] = '|';
            for (int i = 1; i <= a; i++)
                M[x][y++] = '*', M[x][y++] = '|';
            //偶数行
            x = point2 + 2 + 2 * (i - 1), y = 1;
            M[x][y++] = '+';
            for (int i = 1; i <= a; i++)
                M[x][y++] = '-', M[x][y++] = '+';
        }
        //打印侧面
        for (int i = 1; i <= c; i++)
        {
            //奇数行
            int x = 2 + 2 * (i - 1), y = point3;
            M[x++][y--] = '|';
            for (int i = 1; i <= b; i++)
                M[x++][y--] = '*', M[x++][y--] = '|';
            //偶数行
            x = 3 + 2 * (i - 1), y = point3;
            M[x++][y--] = '+';
            for (int i = 1; i <= b; i++)
                M[x++][y--] = '/', M[x++][y--] = '+';
        }
        //输出
        for (int i = 1; i <= point2 + 2 * c; i++)
        {
            for (int j = 1; j <= point3; j++)
                cout << M[i][j];
            cout << endl;
        }
    }
    return 0;
}