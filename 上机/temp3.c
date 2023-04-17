#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sort(long long *a,int n)
{
    long long i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        for(j=i-1;j>=0&&a[j]<=t;j--)
            a[j+1]=a[j];
        a[j+1]=t;
    }
}
int main(void)
{
    long long  i,t,n,*a,sum;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        a=(long long*)malloc(sizeof(long long)*n);
        for(i=0;i<n;i++)scanf("%lld",a+i);
        sort(a,n);
        for(i=sum=0;i<n;i++)
        {
            sum+=abs(a[i]-i-1);
        }
        printf("%lld\n",sum);
        free(a);
    }
}