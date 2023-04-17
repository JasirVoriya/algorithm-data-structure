#include <stdio.h>
int main(void)
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        int index;
        int arry[20100] = {0};
        for (int i = 0; i < n + m; i++)
        {
            scanf("%d", &index);
            arry[index]++;
        }
        for(int i=0;i<20100;i++)
            if(arry[i])printf("%d ",i);
        putchar('\n');
    }
}