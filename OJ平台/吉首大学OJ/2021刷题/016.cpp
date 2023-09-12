/*
问题 G: 阶乘求和
描述
求1+2!+3!+...+N!的和 
要求使用递归实现 
long long  forOne(int X); // 计算单个数的阶乘 X为正整数   
long long forAll(int N); // 全部数值计算 N为正整数 

格式
输入格式
正整数N（N〈=20） 

输出格式
1+2!+3!+...+N!的和 (结果为整数形式) 

样例
样例输入 Copy
3
样例输出 Copy
9		
*/

#include<stdio.h>
long long forOne(int x) // 计算单个数的阶乘 X为正整数
{
    if(x==1)return x;
    else return x*forOne(x-1);
}
long long forAll(int n) // 全部数值计算 N为正整数
{
    if(n==1)return 1;
    else return forOne(n)+forAll(n-1);
}
int main(void)
{
    int n;
    scanf("%d",&n);
    if(n<=0||n>20)return 1;
    printf("%ld",forAll(n));
    return 0;
}