#include <stdio.h>
#include <string.h>
struct A
{
    int a;
    char id, status[5];
};
typedef struct A TEAM;

int fun(char x)
{
    int z;
    z = x - 'A' + 1;
    return z;
}
int main()
{
    int T, i = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, a[60][20] = {0}, b[60] = {0};
        TEAM team[1010];
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d %c %s", &team[i].a, &team[i].id, team[i].status);
            //printf("%d %c %s\n", team[i].a, team[i].id, team[i].status);
            if (strcmp(team[i].status, "AC") == 0)
                a[team[i].a][fun(team[i].id)] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 13; j++)
                if (a[i][j] == 1)
                    b[i]++;
        printf("Case #%d:\n", ++i);
        for (int i = 1; i < n; i++)
            printf("%d ", b[i]);
        printf("%d\n", b[n]);
    }
}
