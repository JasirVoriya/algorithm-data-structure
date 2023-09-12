#include <stdio.h>
int main()
{
    double x1, y1, x2, y2, i, j, t;
    double k, a, b;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    printf("%lf %lf %lf %lf\n",x1,y1,x2,y2);
    k = (y2 - y1) / (x2 - x1); //斜率
    b = y1 - k * x1;           //截距
    printf("%llf %llf\n",k,b);
    int n = 0;
    for (i = x1 + 1; i <= x2 - 1; i++)
    {
        j = k * i + b;
        printf("j:%llf->%d\n",j,(int)j);
        if (j == (int)j)
            n++;
    }
    printf("%d", n);
}
