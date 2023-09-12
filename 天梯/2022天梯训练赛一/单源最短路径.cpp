#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
int main(void) {
    int n, s, d;
    cin >> n >> s >> d;
    unordered_map<int, unordered_map<int, unsigned char>> arr;
    set<int> keys;
    for (int i = 0; i < n; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        if (arr.count(v1) == 0) {
            arr[v1] = unordered_map<int, unsigned char>();
        }
        arr[v1][v2] = w;
        keys.insert(v1);
        keys.insert(v2);
    }

    for (auto k = keys.begin(); k != keys.end(); k++) {
        for (auto i = keys.begin(); i != keys.end(); i++) {
            for (auto j = keys.begin(); j != keys.end(); j++) {
                if (arr.count(*i) && arr.count(*k)) {
                    if (arr[*i].count(*j) == 0) arr[*i][*j] = 255;
                    if (arr[*i].count(*k) == 0) arr[*i][*j] = 255;
                    if (arr[*k].count(*j) == 0) arr[*i][*j] = 255;
                    arr[*i][*j] =
                        min(arr[*i][*k] + arr[*k][*j], (int)arr[*i][*j]);
                }
            }
        }
    }
    if (arr[s][d] != 255) {
        cout << (int)arr[s][d];
    } else {
        cout << -1;
    }
    return 0;
}