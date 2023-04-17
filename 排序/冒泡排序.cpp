#include <stdio.h>
int main(void)
{
    int a[10]={0,1,2,3,4,5,6,7,8,9},n=10,i,j;
    for (i = n - 1; i >= 0; i--) //排序
    {
        for (j = n - 1; j >= n - i; j--)
        {
            if(a[j]>a[j-1])
            {
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
        }
        printf("%d ",a[n-i-1]);
    }
}