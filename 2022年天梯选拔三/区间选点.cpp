#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back(pair<int, int>(x, y));
    }
    sort(arr.begin(), arr.end());
    int end = arr[0].second;
    int ans = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].first > end) {
            ans++;
            end = arr[i].second;

        } else
            end = min(arr[i].second, end);
    }
    cout << ans << endl;
    return 0;
}