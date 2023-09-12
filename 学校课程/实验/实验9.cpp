#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
void fun1(const char *str)
{
    int alpha = 0, space = 0, num = 0, onther = 0;
    for (int i = 0; str[i]; i++)
    {
        if (isalpha(str[i]))
            alpha++;
        else if (isalnum(str[i]))
            num++;
        else if (isspace(str[i]))
            space++;
        else
            onther++;
    }
    printf("alpha:%d\nspace:%d\nnum:%d\nonther:%d\n",
           alpha, space, num, onther);
    return;
}


bool isprime(int n)
{
    if(n<2)return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return false;
    return true;
}
void fun2(int n)
{
    for(int i=6;i<=n;i+=2)
    {
        printf("%d",i);
        for(int j=3;j<=i/2;j+=2)
        {
            if(isprime(j)&&isprime(i-j))
                printf(" =%d+%d",j,i-j);
        }
        putchar('\n');
    }
    return;
}


int cmp(const void* a,const void* b)
{
    return *(double*)b-*(double*)a;
}
void fun3(double *array,int n)
{
    qsort(array,n,sizeof(double),cmp);
    for(int i=0;i<n;i++)
        printf("%g ",array[i]);
    putchar('\n');
}
int main(void)
{
    fun1("12345  qas !@w zx!@#$%");


    fun2(2000);


    double array[]={-1,41,0,-511,-5.55,2,3.5};
    fun3(array,sizeof(array)/sizeof(double));


    return 0;
}