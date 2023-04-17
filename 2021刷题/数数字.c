#include<stdio.h>
int main(void)
{
    long long n;
    while(~scanf("%lld",&n))
    {
        printf("%d\n",n/2+n/3+n/5-n/6-n/10-n/15+n/30);
    }
    return 0;
}
