#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
struct edge {
    int next, time;
    bool operator<(const edge& e) const
    {
        return this->time < e.time;
    }
    edge(int next, int time)
        : next(next)
        , time(time) {};
};
bool vis[MAX_N];
int ans = INF;
bool success = false;
vector<int> watch;
void solove(const vector<vector<edge>>& arr, int prec, int n, int t, int cnt)
{
    if (prec == n && cnt == n) {
        ans = t;
        success = true;
    }
    vis[prec] = true;
    for (auto e : arr[prec]) {
        if (success == true)
            break;
        if (vis[e.next] == false) {
            watch.push_back(e.next);

            for (int v : watch) {
                cout << v << " ";
            }
            cout << endl;

            solove(arr, e.next, n, t + e.time, cnt + 1);
            watch.pop_back();
        }
    }
    vis[prec] = false;
}
int main(void)
{
    int n;
    while (cin >> n) {
        vector<vector<edge>> vec(n + 1);
        for (int prec = 1; prec <= n; prec++) {
            for (int next = 1, time; next <= n; next++) {
                cin >> time;
                if (prec == next)
                    continue;
                vec[prec].push_back(edge(next, time));
            }
            sort(vec[prec].begin(), vec[prec].end());
        }
        ans = INF, success = false;
        solove(vec, 1, n, 0, 1);
        cout << ans << endl;
    }
    return 0;
}