#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int root[MAX_N];
int book[MAX_N] = { 0 };
bool cmp(int a, int b)
{
    return a > b;
}
void init()
{
    for (int i = 0; i < MAX_N; i++) {
        root[i] = -1;
    }
}
int finds(int x)
{
    if (root[x] == x)
        return x;
    return root[x] = finds(root[x]);
}
void union_set(int x, int y)
{
    root[finds(x)] = root[finds(y)];
}
bool is_set(int x, int y)
{
    return finds(x) == finds(y);
}
void add(int x)
{
    for (int i = 1; i < MAX_N; i++) {
        if (root[i] == root[x])
            book[i]++;
    }
}
int main(void)
{
    init();
    int n;
    cin >> n;
    while (n--) {
        int k, x, y;
        scanf("%d:", &k);
        getchar();
        cin >> x;
        if (root[x] == -1)
            root[x] = x;
            add(x);
        for (int i = 1; i < k; i++) {
            cin >> y;
            if (root[y] == -1)
                root[y] = y;
            add(y);
            union_set(x, y);
        }
    }
    int ans[MAX_N] = { 0 };
    for (int i = 1; i < MAX_N; i++) {
        if (root[i] == -1 || ans[root[i]] != 0)
            continue;
        ans[root[i]] = book[i];
        for (int j = i + 1; j < MAX_N; j++) {
            if (root[j] == -1)
                continue;
            if (is_set(i, j)) {
                ans[root[i]] = max(ans[root[i]], book[j]);
            }
        }
    }
    sort(ans, ans + MAX_N, cmp);
    int cnt = MAX_N - count(ans, ans + MAX_N, 0);
    cout << cnt << endl;
    cout << ans[0];
    for (int i = 1; i < MAX_N; i++) {
        if (ans[i] == 0)
            break;
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}