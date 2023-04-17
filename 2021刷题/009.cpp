#include<stdio.h>
int main(void)
{
    int i,num;
    char bit[5];
    scanf("%d",&num);
    for(i=0;num;i++,num/=10) bit[i]=num%10;
    printf("%d\n",i);
    for(num=i-1;num>=0;num--) printf("%d ",bit[num]);
    putchar('\n');
    for(num=0;num<i;num++) printf("%d ",bit[num]);
    return 0;
}