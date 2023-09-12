#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10000000;
float arr[MAX_N];
bool cmp(float x, float y)
{
    return x - y < 0.000001;
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    int num;
    cin >> num;
    while (num--) {
        int x;
        cin >> x;
        if ((x >= 0 && x < n) == false) {
            cout << -1 << endl;
        } else {
            cout << arr[x] << endl;
        }
    }
    return 0;
}