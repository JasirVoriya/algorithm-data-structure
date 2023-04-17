#include<stdio.h>
typedef unsigned long long ull;
int main(void)
{
    ull ans=1;
    int n;
    while(~scanf("%d",&n))printf("%llu\n",(ans<<n)-1);
}