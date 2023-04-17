//牛顿迭代法
#include <stdio.h>
double sqrt2(double n)
{
    if (n == 0)//特殊情况
        return 0;
    double x0, x1 = 1.0;
    do{
        x0 = x1;//先将当前值存起来
        x1 = (x0 + n / x0) / 2;//再去计算下一个值
    } while (x1 != x0);//当误差小于 1e-6 次方的时候，结束循环
    return x1;//返回答案
}
int main(void)
{
    long long n;
    scanf("%lld",&n);
    printf("%llf", sqrt2(n));
}