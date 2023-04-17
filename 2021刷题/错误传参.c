#include<stdio.h>
void fun(int,int);
void fun2(double,double);
int main(void)
{
    fun2(4444444444444444,2.4);
}
void fun2(double a,double b)
{
    printf("%lf %lf",a,b);
}
void fun(int a,int b)
{
    printf("%d %d",a,b);
}