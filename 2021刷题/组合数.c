#include<stdio.h>
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        
        int sum=1;
        for(int i=m+1;i<=n;i++)sum*=i;
        n=n-m;
        while(n>1) sum/=n--;
        printf("%d\n",sum);
    }
}