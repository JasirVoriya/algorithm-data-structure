#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
char m[maxn][maxn];
int ans = 0;
int w, h;
void solove(int x, int y)
{
    m[y][x] = '#';
    int nx, ny;
    for (int i = -1; i <= 1; i++) //偏移x轴
    {
        nx = x + i, ny = y;
        if (nx >= 0 && nx < w && ny >= 0 && ny < h && m[ny][nx] == '.')
        {
            // cout << "(ny,nx):" << ny << ' ' << nx << ':';
            // cout << ++ans << endl;
            ++ans;
            solove(nx, ny);
        }
    }
    for (int i = -1; i <= 1; i++) //偏移y轴
    {
        nx = x, ny = y + i;
        if (nx >= 0 && nx < w && ny >= 0 && ny < h && m[ny][nx] == '.')
        {
            // cout << "(ny,nx):" << ny << ' ' << nx << ':';
            // cout << ++ans << endl;
            ++ans;
            solove(nx, ny);
        }
    }
}
int main(void)
{
    int x, y;
    while (cin >> w >> h)
    {
        if (w <= 0 && h <= 0)
            break;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                cin >> m[i][j];
                if (m[i][j] == '@')
                    x = j, y = i;
            }
        ans = 1;
        //cout << x << y;
        solove(x, y);
        cout << ans << endl;
    }
    return 0;
}