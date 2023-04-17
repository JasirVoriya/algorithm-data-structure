#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int maxn = 1e4 + 5;
char mid[maxn], pre[maxn], post[maxn];
struct node {
    int val;
    node *l = nullptr, *r = nullptr;
};
void solve(int s, int len) {
    auto val = post[s];
    int i = 1;
    while (val != mid[i]) i++;
    solve(i - 1, i);
    solve(i + 1, len - i); 
}
int main(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> mid[i];
    for (int i = 1; i <= n; i++) cin >> post[i];
    return 0;
}