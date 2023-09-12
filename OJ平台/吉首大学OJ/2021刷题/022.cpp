/*
问题 F: 质数因子
描述


输入一个正整数，输出它的所有质数的因子（如180的质数因子为2、2、3、3、5） 

格式
样例
样例输入 Copy
180
样例输出 Copy
2 2 3 3 5 
*/
#include<stdio.h>
int main(void)
{
    int n,i;
    scanf("%d",&n);
    for(i=2;n!=1;i++)
    {
        while(n%i==0)
        {
            printf("%d ",i);
            n/=i;
        }
    }
}