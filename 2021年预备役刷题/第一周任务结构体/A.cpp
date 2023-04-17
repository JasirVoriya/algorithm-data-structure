#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3e3 + 5;
int arr[MAX_N];
int res[MAX_N * MAX_N / 2];
int main(void)
{
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res[index++] = arr[i] + arr[j];
            }
        }
        sort(res, res + index, [](int a, int b) -> bool { return a > b; });
        for (int i = 0; i < m; i++) {
            cout << res[i] << (i == m-1 ? "\n" : " ");
        }
    }
    return 0;
}