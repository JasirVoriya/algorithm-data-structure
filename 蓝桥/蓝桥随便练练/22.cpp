#include <bits/stdc++.h>
using namespace std;
struct node
{
    int begin, end;
} programes[110];
bool cmp(node &a, node &b)
{
    return a.end < b.end;
}
int main(void)
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            cin >> programes[i].begin >> programes[i].end;
        sort(programes, programes + n, cmp);
        int ans = 1;
        int end = programes[0].end;
        for (int i = 1; i < n; i++)
        {
            if (end <= programes[i].begin)
                end = programes[i].end, ans++;
        }
        cout << ans << endl;
    }
    return 0;
}