
/*
1035: 找中间数
描述
输入三个整数，找出其中数值的中间数。

格式
输入格式
输入3个整数。

输出格式
输出中间数

样例
样例输入 Copy
1 2 3
样例输出 Copy
2
*/
#include<stdio.h>
void swap(int*a,int *b)
{
    int t;
    t=*a,*a=*b,*b=t;
}
int main(void)
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a<b)swap(&a,&b);
    if(a<c)swap(&a,&c);
    if(b<c)swap(&b,&c);
    printf("%d",b);
    return 0;
}