#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cin >> n;
    while (n--) {
        int a, l, r;
        cin >> a >> l >> r;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (arr[mid] == a) {
                cout << mid << endl;
                break;
            } else if (a < arr[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (l > r)
            cout << -1 << endl;
    }

    return 0;
}