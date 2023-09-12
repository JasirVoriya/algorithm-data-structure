/*
1033: C语言实验题——求级数值(JSU-ZJJ)
描述
求下列级数的值

1-1/2+1/3-......-1/100

格式
输入格式
无

输出格式
级数的值，以float浮点数输出,保留6位小数。
*/
#include<stdio.h>
#define N 100
int main(void)
{
    int i,flag;
    float sum;
    for(flag=i=1,sum=0;i<=N;i++,flag*=-1)
        sum+=flag/(float)i;  
    printf("%.6f",sum);
}