#include <bits/stdc++.h>
#define PI acos(-1)
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAX_N = 1e3;
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    queue<int> que;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (que.empty()) {
                cout << "EMPTY ";
            } else {
                cout << que.front() << " ";
                que.pop();
            }
        } else {
            if (que.size() >= 10) {
                cout << "FULL ";
            } else {
                que.push(x);
            }
        }
    }
    cout << endl;
    while (que.size()) {
        cout << que.front() << " ";
        que.pop();
    }
    return 0;
}