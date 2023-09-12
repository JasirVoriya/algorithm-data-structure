#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 5;
int arr[MAX_N];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> arr[i];
    int x, y;
    cin >> x >> y;
    for (int i = 0; i + 1 < n; i++) {
        if (arr[i] == x && arr[i + 1] == y || arr[i] == y && arr[i + 1] == x) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")