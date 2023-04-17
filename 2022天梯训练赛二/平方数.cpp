#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
bool vis[MAX_N];
void init()
{
    for (int i = 0; i < MAX_N; i++) {
        int x = sqrt(i);
        if (x * x == i)
            vis[i] = true;
    }
}
int main(void)
{

    init();
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            break;
        int cnt = 0;
        while (a <= b) {
            cnt += vis[a++];
        }
        cout << cnt << endl;
    }

    return 0;
}