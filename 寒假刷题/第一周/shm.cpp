#include <stdio.h>
#include <math.h>
struct student
{
    double a, b, c;
} str[10009], head;
int main()
{
    int n, m; //n是数目m是剩下时间
    while (~scanf("%d%d", &n, &m))
    {
        if (m == 0 && n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &str[i].a, &str[i].b);
            str[i].c = str[i].b / str[i].a;
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (str[j].c < str[j + 1].c)
                {
                    head = str[j];
                    str[j] = str[j + 1];
                    str[j + 1] = head;
                }
            }
        }
        int sum;
        sum = 0;
        double jz = 0.0;
        for (int i = 0; i < n; i++)
        {
            sum += str[i].a;
            if (sum <= m)
            {
                jz += str[i].b;
            }
            else
            {
                jz += str[i].c * (str[i].a - (sum - m));
                break;
            }
        }
        printf("%.2lf\n", jz);
    }
}
