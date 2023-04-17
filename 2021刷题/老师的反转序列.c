#include <stdio.h>
int main(void)
{
    long long n, m;
    while (~scanf("%lld%lld", &n, &m))
        printf("%lld\n", (n / (2 * m)) * m * m);
}