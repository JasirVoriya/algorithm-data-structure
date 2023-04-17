#include<stdio.h>
void fun(int i,int n)
{
    if(i==0)
    {
        printf("%*c\n",n/2+1,'*');
        fun(i+1,n);
        printf("%*c\n",n/2+1,'*');
        return;
    }
    if(i==n/2)
    {
        printf("*%*c\n",n-1,'*');
        return;
    }
    printf("%*c%*c\n",n/2+1-i,'*',2*i,'*');
    fun(i+1,n);
    printf("%*c%*c\n",n/2+1-i,'*',2*i,'*');
}
int main(void)
{
    int n;
    scanf("%d",&n);
    fun(0,n);
    return 0;
}