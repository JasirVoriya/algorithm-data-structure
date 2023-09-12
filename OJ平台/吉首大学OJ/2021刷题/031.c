/*
问题 N: An Easy Task
描述
Ignatius was born in a leap year, so he want to know when he could hold his birthday party. Can you tell him?

Given a positive integers Y which indicate the start year, and a positive integer N, your task is to tell the Nth leap year from year Y.

Note: if year Y is a leap year, then the 1st leap year is year Y.

格式
输入格式
The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
Each test case contains two positive integers Y and N(1<=N<=10000).

输出格式
For each test case, you should output the Nth leap year from year Y.

样例
样例输入 Copy
3
2005 25
1855 12
2004 10000
样例输出 Copy
2108
1904
43236
*/
#include<stdio.h>
int isleap(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return 1;
    return 0;
}
int main(void)
{
    int t,y,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&y,&n);
        for(i=0;i<n;y++) if(isleap(y))i++;
        printf("%d\n",y-1);
    }
}