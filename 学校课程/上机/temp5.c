#include <stdio.h>
#define SIZE (50 * 50 + 50 + 41 + 1)
int a[SIZE] = {1, 1};
void init()
{
    int i = 2, j;
    while (i < SIZE)
    {
        for (j = 2 * i; j < SIZE; j += i)
            a[j] = 1;
        while (a[++i])
            ;
    }
}
int main(void)
{
    init();
    int x,y;
    while(scanf("%d%d",&x,&y),x||y)
    {
        while(x<=y&&!a[x*x+x+41])x++;
        if(x>y)puts("OK");
        else puts("Sorry");
    }
}