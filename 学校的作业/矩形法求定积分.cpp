#include<stdio.h>
#include<math.h>
const double pi=3.1415926;
double sum(double (*fun)(double),double a,double b)
{
    double n=1e7;
    double x=(b-a)/n,sum=0;
    for(int i=1;i<=n;i++)
        sum+=fun(x*i)*x;
    return sum;
}
int main(void)
{
    printf("%lf\n",sum(sin,0,pi));
    printf("%lf\n",sum(cos,0,pi/2));
    return 0;
}