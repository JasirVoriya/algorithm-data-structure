#include <stdio.h>
#include <string.h>
struct s
{
    char id[1000];
    int num;
    int score[100];
    int sum;
} x[1000];
int main()
{
    freopen("input.txt", "r", stdin);
    int n, m, g, a[10], amount, i, j;
    while (~scanf("%d", &n) && n > 0)
    {
        scanf("%d%d", &m, &g);
        for (i = 1; i <= m; i++) //输入每题分数
        {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; i++) //输入每个考生信息
        {
            amount = 0;
            scanf("%s%d", x[i].id, &x[i].num); //输入学号 和 解题数量
            for (j = 0; j < x[i].num; j++)     //输入解题题号，算总分
            {
                int index;
                scanf("%d", &index);
                x[i].score[j] = a[index];
                amount += x[i].score[j];
            }
            x[i].sum = amount;
        }

        int count = 0;
        for (i = n - 1; i >= 0; i--) //排序
        {
            for (j = n - 1; j >= n - i; j--)
            {
                if (x[j].sum > x[j - 1].sum ||
                    x[j].sum == x[j - 1].sum && strcmp(x[j].id, x[j - 1].id) < 0)
                {
                    struct s temp = x[j];
                    x[j] = x[j - 1];
                    x[j - 1] = temp;
                }
            }
            if (x[n - i - 1].sum >= g) //统计过了分数线的人数
                count++;
        }
        //输出
        printf("%d\n", count);
        for (i = 0; i < count; i++)
        {
            printf("%s %d\n", x[i].id, x[i].sum);
        }
    }
}