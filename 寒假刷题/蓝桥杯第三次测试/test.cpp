#include <bits/stdc++.h>
using namespace std;
void fun(int x)
{
    cout << x;
    getchar();
    if (x % 2 == 0)
        fun(3 * x / 2);
    else
        fun(x - 1);
}
int main(void)
{
    fun(5);
    return 0;
}