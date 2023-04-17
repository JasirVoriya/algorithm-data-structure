#include <stdio.h>
int main(int argc, char *argv[])
{
    void loser(int (*)[5]);
    int a[5][5];
    int i, j, n, m;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        a[i][0] = i+1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int (*p)[5]=a;
    avg(p);
    loser(a);
    winner(a);
    return 0;
}
void avg(int p[][5])
{
    int i, j, sum=0;
    for (i = 0; i <5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            sum += *(*(p + i) + j);
        }
    }
    printf("%lf\n", sum / 5.0);
}
void loser(int (*p)[5])
{
    int i, j, ans, count = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            if (*(*(p + i) + j) < 60)
            {
                count++;
            }
        }
        if (count >= 2)
        {
            count = 0;
            printf("%d:", **(p + i));
            for (j = 1; j < 5; j++)
            {
                if (*(*(p + i) + j) < 60)
                {
                    printf("%d ", *(*(p + i) + j));
                }
            }
            printf("\n");
        }
    }
}
void winner(int (*p)[5])
{
    int i, j, sum = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            sum += *(*(p + i) + j);
        }
        double t = sum / 4.0;
        if (t >= 85 && t <= 90)
        {
            printf("%d\n", **(p + i));
        }
        sum = 0;
    }
}