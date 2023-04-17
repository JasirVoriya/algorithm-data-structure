#include <bits/stdc++.h>
using namespace std;
bool a[6][6];
bool vis[6][6];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
struct Pos
{
    int x, y;
};
stack<Pos> s;
// void fun(int x, int y)
// {
//     vis[x][y] = true;
//     for (int i = 0; i < 4; i++)
//     {
//         int nx = dx[i] + x, ny = dy[i] + y;
//         if (nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5 && !vis[nx][ny])
//         {
//             Pos t = {nx, ny};
//             s.push(t);
//             fun(nx, ny);
//             s.pop();
//         }
//     }
// }
int main(void)
{
    set<Pos> s[25];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> a[i][j];
    Pos t = {0, 0};
    vis[0][0]=true;
    s[0].insert(t);
    for (int i = 1; i < 25; i++)
    {
        for (auto it = s[i].begin(); it != s[i].end(); it++)
        {
            for (int j = 0; j < 4; j++)
            {
                int nx = dx[j] + it->x, ny = dy[j] + it->y;
                if (nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5 && !vis[nx][ny])
                {
                    vis[nx][ny]=true;
                    Pos t={nx,ny};
                    s[i].insert(t);
                }
            }
        }
    }
    return 0;
}