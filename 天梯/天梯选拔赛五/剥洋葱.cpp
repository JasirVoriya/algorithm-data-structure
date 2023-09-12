#include <bits/stdc++.h>
using namespace std;
char g[1000] = {0};
int size;
void fun(int i, int n)
{
    if (i == n - 1)
    {
        int begin = 1 + i, end = size - i;
        while (begin <= end)
        {
            g[begin] = g[end] = 'A' + i;
            begin++, end--;
        }
        puts(g + 1);
        begin = 1 + i, end = size - i;
        while (begin <= end)
        {
            g[begin] = g[end] = 'A' + i - 1;
            begin++, end--;
        }
        return;
    }
    int begin = 1 + i, end = size - i;
    while (begin <= end)
    {
        g[begin] = g[end] = 'A' + i;
        begin++, end--;
    }
    puts(g + 1);
    fun(i + 1, n);
    puts(g + 1);
    begin = 1 + i, end = size - i;
    while (begin <= end)
    {
        g[begin] = g[end] = 'A' + i - 1;
        begin++, end--;
    }
}
int main(void)
{
    int n;
    cin >> n;
    size = 2 * n - 1;
    fun(0, n);
    return 0;
}