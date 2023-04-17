#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    int t;
    cin >> t;
    int arr[MAX_N];
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int x1 = (n - 1) / 2, x2 = n / 2;
        int y1 = 0, y2 = 0;
        for (int i = 0; i < n; i++) {
            y1 += abs(arr[i] - arr[x1]);
            y2 += abs(arr[i] - arr[x2]);
        }
        cout << min(y1, y2) * 2 << endl;
    }
    return 0;
}