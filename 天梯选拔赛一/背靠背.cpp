#include <bits/stdc++.h>
using namespace std;
void fun(char c, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int x = n - i;
        while (x--)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << c;
        cout << " ";
        for (int j = 1; j <= i; j++)
            cout << c;
        cout << endl;
    }
}
int main(void)
{
    int n1, n2;
    char c1, c2;
    while (cin >> c1 >> n1)
    {
        fun(c1, n1);
        // fun(c2, n2);
    }
    return 0;
}