#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2 + 5;
typedef long long ll;
typedef unsigned long long ull;
bool vis[MAX_N][MAX_N];
int arr[MAX_N][MAX_N];
int n, m;
int d[4][2] = {
    { 0, -1 },
    { -1, 0 },
    { 0, 1 },
    { 1, 0 }
};
int area = 0, cnt = 0;
void solve(int x, int y)
{
    area++;
    vis[x][y] = true;
    // 0x1,0x2,0x4,0x8
    for (int i = 0; i < 4; i++) {
        if (arr[x][y] & (1 << i) == 0) {
            int dx = x + d[i][0], dy = y + d[i][1];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && vis[dx][dy] == false) {
                solve(dx, dy);
            }
        }
    }
}
int main(void)
{

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int max_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == false) {
                area = 0;
                cnt++;
                solve(i, j);
                max_area = max(max_area, area);
            }
        }
    }
    cout << cnt << endl;
    cout << max_area << endl;
}