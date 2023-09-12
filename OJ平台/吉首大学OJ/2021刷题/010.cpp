#include<stdio.h>
void fun(int a,int b)
{
    if(a==b){
        printf("%d ",a);
        return;
    }
    printf("%d ",a);
    fun(a+1,b);
    printf("%d ", a);
    return;
}
int main(void)
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n-i;j++) printf("  ");
        fun(1,i);
        putchar('\n');
    }
    return 0;
}