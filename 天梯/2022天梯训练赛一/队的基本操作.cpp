#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
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
            if (que.size() == 10) {
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
    cout << endl;
    return 0;
}