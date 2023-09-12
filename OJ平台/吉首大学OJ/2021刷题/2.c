#include<stdio.h>
void fun1()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n)
    {

        printf("%d",n%10);
        n/=10;
    }
    putchar('\n');
}
void fun2()
{

    int i,j,k;
    i=6;
    j=i++;
    k=(--j)+i;
    k=k++;
    printf("%d %d %d\n",i,j,k);
}
void fun3()
{
    char a,b,c;
    scanf("%c%c%c",&a,&b,&c);
    getchar();
    printf("%g\n",(float)(a+b+c)/3);
}
int main(void)
{
    fun1();
    fun2();
    fun3();
    return 0;
}
