#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int main(void)
{
    // x.结束时间 <= y.开始时间
    // 更新x节点
    int n;
    while (cin >> n, n) {
        vector<P> vec;
        for (int i = 0, x, y; i < n; i++) {
            cin >> x >> y;
            vec.push_back(P(y, x));
        }
        sort(vec.begin(), vec.end());
        P prev = vec[0];
        int cnt = 1;
        for (int i = 1; i < vec.size(); i++) {
            if (prev.first <= vec[i].second) {
                prev = vec[i];
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}