//对角线数字之和
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int **a=NULL,n,i,j;
    scanf("%d",&n);
    if(n<=0||n>10)return 1;
    a=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)a[i]=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",a[i]+j);
    }
    for(i=j=0;i<n;i++)
        if(i!=n-1-i)j+=a[i][i]+a[i][n-1-i];
        else j+=a[i][i];
    printf("%d",j);
}