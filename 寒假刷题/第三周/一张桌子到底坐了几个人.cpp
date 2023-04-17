#include <bits/stdc++.h>
using namespace std;
int table[1100];
int find(int x)
{
    while (x != table[x])
        x = table[x] = table[table[x]];
    return x;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            table[i] = i;
        int a, b, roota, rootb;
        while (m--)
        {
            cin >> a >> b;
            roota = find(a), rootb = find(b);
            if (roota != rootb)
            {
                table[roota] = rootb;
                n--;
            }
        }
        cout << n << endl;
    }
    return 0;
}