#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
bool cmp(int a, int b)
{
    return a > b;
}
int ans[MAX_N][MAX_N];
int arr[MAX_N];
int len = 0, cnt = 0;
void solove(int x, int y, int m, int n)
{
    if (n <= 1) {
        while (cnt < len) {
            ans[x++][y] = arr[cnt++];
        }
        return;
    }
    for (int i = 0; i < n - 1; i++)
        ans[x][y + i] = arr[cnt++];

    for (int i = 0; i < m - 1; i++) {
        ans[x + i][y + n - 1] = arr[cnt++];
    }

    for (int i = 0; i < n - 1; i++)
        ans[x + m - 1][y + n - 1 - i] = arr[cnt++];

    for (int i = 0; i < m - 1; i++) {
        ans[x + m - 1 - i][y] = arr[cnt++];
    }
    solove(x + 1, y + 1, m - 2, n - 2);
}
int main(void)
{
    cin >> len;
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    int m = len, n = 1;
    for (int i = 2; i * i <= len; i++) {
        if (len % i == 0)
            n = i;
    }
    m = len / n;
    sort(arr, arr + len, cmp);
    solove(0, 0, m, n);
    for (int i = 0; i < m; i++) {
        cout << ans[i][0];
        for (int j = 1; j < n; j++) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}