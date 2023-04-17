#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 45;
ll fib[maxn] = {0, 1, 1};
void init()
{
    for (int i = 3; i < maxn; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
}
int main(void)
{
    init();
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        printf("%-10d",fib[i]);
        if(i%4==0)putchar('\n');
        i++;
    }
    return 0;
}