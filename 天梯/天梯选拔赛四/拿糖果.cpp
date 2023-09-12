#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 5;
const int max_w = 1e5 + 5;
int a[max_n];
int book[max_w];
int n;
int main(void)
{
    while (cin >> n)
    {
        memset(book, 0, sizeof(book));
        for (int i = 0; i < n; i++)
            scanf("%d", a + i), book[a[i]]++;
        int ans = -1e6;
        for (int i = 0, j, min_w = 0, x; i < n; i++)
        {
            x = a[i];
            book[x]--;
            while (book[min_w] == 0)
                min_w++;
            ans = max(ans, x - min_w);
        }
        cout << ans << endl;
    }
    return 0;
}