// 问题 F : 素数平方和
//              描述
//                  已知正整数n,
//          m(1 < n <= m < 1000)。求[n, m] 区间内所有的素数的平方和。

//          格式
//          输入格式
//          标准输入，输入只有一个用例n,
//          m,
//          即对应的解题区间。

//          输出格式
//          标准输出，将[n, m] 区间内所有素数的平方和用一行输出。

//          样例
//          样例输入 Copy
//          10 100 
//          样例输出 Copy
//          65709
#include <stdio.h>
         int num[1001] = {1, 1};
void init(void)
{
    int i, j;
    i = 2;
    while (i < 1000)
    {
        for (j = 2; i * j <= 1000; j++)
            num[i * j] = 1;
        while (num[++i]);
    }
}
int fun(int n,int m)
{
    int sum=0;
    while(n<=m)
    {
        if(!num[n])sum+=n*n;
        n++;
    }
    return sum;
}
int main(void)
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    if(!(1<n&&n<=m&&m<1000))return 1;
    printf("%d",fun(n,m));
}