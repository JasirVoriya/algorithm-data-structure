#include<stdio.h>
typedef unsigned long long ull;
int main(void)
{
    int n;
    while(~scanf("%d",&n))
    {
        ull ans=0,num;
        while(n--)
        {
            scanf("%llu",&num);
            ans+=num;
        }
        printf("%llu\n",ans);
    }
    return 0;
}