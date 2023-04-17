/*
问题 C: 简单标记法
描述
共T组数据，输入一个T 
每组数据：输入一个n(1<=n<=100)，以及一个大小为n的数组a(0<=a[i]<=100000)，判断a数组中是否存在奇数。如果存在则输出Yes，否则输出No 

格式
输入格式
输入一个T(1<=T<=10) 
每组第一行输入一个n(1<=n<=100) 
第二行输入n个整数a[i](0<=a[i]<=100000) 

输出格式
每组输出结果Yes或者No

样例
样例输入 Copy
1
5
2 4 1 6 8
样例输出 Copy
Yes
*/
#include<stdio.h>
int main(void)
{
    long t,i,n,a[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",a+i);
        for(i=0;i<n;i++){
            if(a[i]%2)
            {
                puts("Yes");
                break;
            }
        }
        if(i==n)puts("No");
    }
}