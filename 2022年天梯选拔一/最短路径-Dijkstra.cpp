#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 15;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int arr[MAX_N][MAX_N];
void init()
{
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            arr[i][j] = i != j ? INF : 0;
}
int main(void)
{
    init();
    int n, m, flag;
    cin >> n >> m >> flag;
    for (int i = 0; i < m; i++) {
        int x, y, dis;
        cin >> x >> y >> dis;
        arr[x][y] = dis;
        if (flag==0)
            arr[y][x] = dis;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    int start;
    cin >> start;
    for (int i = 1; i <= n; i++) {
        cout << start << "->" << i << ":";
        if (arr[start][i] == INF)
            cout << "no path" << endl;
        else
            cout << arr[start][i] << endl;
    }
    return 0;
}