//选择排序
#include<stdio.h>
#define N 10
#define swap(x,y){int t;t=x;x=y;y=t;}
int main(void)
{
    int a[N]={0},i,j,min,t;
    for(i=0;i<N;i++)scanf("%d",a+i);
    for(i=0;i<N-1;i++)
    {
        min=i;
        for(j=i+1;j<N;j++) if(a[min]>a[j])min=j;
        if(min!=i)swap(a[min],a[i]);
        printf("%d\n",a[i]);
    }
    printf("%d\n",a[N-1]);
}