#include<stdio.h>
int main(void)
{
    int n;
    while(~scanf("%d",&n))
    {
        int sum=0,base=1;
        for(int i=0;i<n;i++)
        {
           sum+=base;
           base=(base*2)%107;
        }
        printf("%d\n",sum);
    }
}