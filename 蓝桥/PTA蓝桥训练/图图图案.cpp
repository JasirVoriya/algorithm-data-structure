#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2;
char graph[maxn][maxn] = {0};
int main(void)
{
    int n;
    cin >> n;
    int size = 2 * n - 1;
    char G = 'A' + n - 1;
    graph[n][n] = G;
    for (int x = 1; true; x++)
    {
        G--;
        if (G < 'A')
            break;
        graph[n - x][n - x] = G;
        graph[n + x][n + x] = G;
        graph[n - x][n + x] = G;
        graph[n + x][n - x] = G;
        graph[n][n + x] = G;
        graph[n][n - x] = G;
        graph[n - x][n] = G;
        graph[n + x][n] = G;
    }
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
            if (graph[i][j])
                cout << graph[i][j];
            else
                cout << ".";
        cout << endl;
    }
    return 0;
}