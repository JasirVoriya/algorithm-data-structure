#include <stdio.h>
int n, a, k, killed, overKill;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void sort(int *arry, int begin, int end)
{
    if (end == 0)
        return;
    if (begin == end - 1)
    {
        if (arry[begin] - a == 0)
            overKill = 0;        //杀掉随从，但是没有触发超杀
        if (arry[begin] - a < 0) //触发超杀，killed把被杀随从的血量存下来
        {
            overKill = 1; //触发超杀
            killed = arry[begin];
            // printf("arry[%d]->x->%d\na->%d\n",begin,x,a);
            return;
        }
        sort(arry, 0, end - 1);
        return;
    }
    if (arry[begin] > arry[begin + 1])
    {
        swap(arry + begin, arry + begin + 1);
        sort(arry, begin + 1, end);
        swap(arry + begin, arry + begin + 1);
        return;
    }
    sort(arry, begin + 1, end);
}
int main(void)
{
    int t, hp[1100];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &a, &k);
        int num = 0, i, stop;
        for (i = 0; i < n; i++)
            scanf("%d", hp + i);
        overKill = -1;
        sort(hp, 0, n);
        if (overKill == -1)
            puts("0");
        else if (overKill == 0)
            puts("1");
        else
        {
            int skip = 0;
            for (i = 0, num = 1; i < n; i++)
            {
                if (!skip && hp[i] == killed)
                {
                    skip = 1;
                    continue;
                }
                if (hp[i] - k <= 0)
                    num++;
                if (hp[i] - k >= 0)
                    break;
            }
            printf("%d\n", num);
        }
    }
}
