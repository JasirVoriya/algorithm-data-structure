/*
1034: 逆置正整数
描述
输入一个三位数的个正整数，将它反向输出。

格式
输出格式
逆置后的正整数

样例
样例输入 Copy
123
样例输出 Copy
321
*/
#include<stdio.h>
int main(void)
{
    int i,a,b=0;
    scanf("%d",&a);
    if(a<=0)return 1;
    while(a)
    {
        b=b*10+a%10;
        a/=10;
    }
    printf("%d",b);
    return 0;
}