#include<stdio.h>
#include<stdlib.h>
int cmp1(const void* a,const void* b)
{
    return *(char*)a-*(char*)b;
}
int cmp2(const void* a,const void* b)
{
    return *(char*)b-*(char*)a;
}
int fun1(int n)
{
    if(n==6174)return 1;
    char str[5]={0};
    itoa(n,str,10);
    qsort(str,4,sizeof(char),cmp2);
    int max=atoi(str);
    qsort(str,4,sizeof(char),cmp1);
    int min=atoi(str);
    return fun1(max-min)+1;

}
// int fun2(const char* str)
// {
//     int ans=0;
//     while(*str)
//     {
//         while(*str&&*str==' ')str++;
//         if(!*str)
//     }
// }
double fun3(double a,double b,double c,double d)
{
    double last=0;
    double res=1;
    while (res!=last)
    {
        double y=a*res*res*res+b*res*res+c*res+d;
        double y_=3*a*res*res+2*b*res+c;
        last=res;
        res-=y/y_;
    }
    return res;
}
int main(void)
{
    printf("%d\n",fun1(1234));
    return 0;
}