#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int d[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
struct node {
    int x, y, step;
    node(int x, int y, int step)
        : x(x)
        , y(y)
        , step(step) {};
};
int main(void)
{
    int n;
    cin >> n;
    while (n--) {
        bool m[MAX_N][MAX_N] = { 0 };
        bool vis[MAX_N][MAX_N] = { 0 };
        int a, b, c;
        cin >> a >> b >> c;
        int x, y;
        while (c--) {
            cin >> x >> y;
            m[x][y] = true;
        }
        int bx, by, ex, ey;
        cin >> bx >> by >> ex >> ey;
        queue<node> que;
        que.push(node(bx, by, 0));
        vis[bx][by] = true;
        bool success = false;
        while (que.size()) {
            node t = que.front();
            if (t.x == ex && t.y == ey) {
                cout << t.step << endl;
                success = true;
                break;
            }
            que.pop();
            for (int i = 0; i < 4; i++) {
                int dx = t.x + d[i][0], dy = t.y + d[i][1], s = t.step + 1;
                if (dx >= 0 && dx < a && dy >= 0 && dy < b && m[dx][dy] == false && vis[dx][dy] == false) {
                    que.push(node(dx, dy, s));
                    vis[dx][dy] = true;
                }
            }
        }
        if (success == false) {
            cout << "Not arrive" << endl;
        }
    }

    return 0;
}