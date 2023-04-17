#include <iostream>
using namespace std;
const int maxn = 15;
char Map[maxn][maxn];
char Visited[maxn][maxn];
int n;
char solove(int i, int j)
{
    int ni, nj, ans = 0;
    for (int di = -1; di <= 1; di++)
        for (int dj = -1; dj <= 1; dj++)
        {
            ni = i + di, nj = j + dj;
            if (di == 0 && dj == 0)
                continue;
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && Map[ni][nj] == '*')
                ans++;
        }
    return ans + '0';
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Map[i];
    for (int i = 0; i < n; i++)
        cin >> Visited[i];
    bool alive = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Visited[i][j] == 'x')
            {
                if (Map[i][j] == '*')
                    alive = false;
                else
                    Visited[i][j] = solove(i, j);
            }
        }
    }
    if (alive == false)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (Map[i][j] == '*')
                    Visited[i][j] = '*';
    for (int i = 0; i < n; i++)
        cout << Visited[i] << endl;
    return 0;
}