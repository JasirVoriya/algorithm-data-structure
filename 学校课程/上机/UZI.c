#include <stdio.h>
#define MOD 1000000007L
#define SIZE 10000100L
long long a[SIZE] = {1, 1};
void init()
{
    for (long long i = 2; i < SIZE; i++)
        a[i] = (a[i - 1] % MOD + a[i - 2] % MOD) % MOD;
}
int main()
{
    init();
    long long n;
    while (~scanf("%lld", &n))
        printf("%lld\n", a[n]);
}
