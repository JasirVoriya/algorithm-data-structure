#include <stdio.h>
#define SIZE 3
#define swap(x, y) \
    {              \
        int t = x; \
        x = y;     \
        y = t;     \
    }
void fun1(void)
{
    int a[SIZE][SIZE], i, sum;
    for (i = 0; i < SIZE * SIZE; i++)
        scanf("%d", *a + i);
    sum = SIZE % 2 ? -a[SIZE / 2][SIZE / 2] : 0;
    for (i = 0; i < SIZE; i++)
        sum += a[i][i] + a[i][SIZE - 1 - i];
    printf("%d\n", sum);
}
void fun2()
{
    int a[SIZE], i, j;
    for (i = 0; i < SIZE; i++)
        scanf("%d", a + i);
    i = 0, j = SIZE - 1;
    while (i < j)
    {
        swap(a[i], a[j]);
        i++, j--;
    }
    for(i=0;i<SIZE;i++)printf("%d ",a[i]);
}
void fun3()
{
    int a[10],i,j,min;
    for(i=0;i<10;i++)scanf("%d",a+i);
    for(i=0;i<10;i++)
    {
        min=i;
        for(j=i+1;j<10;j++)if(a[j]<a[min])min=j;
        if(min!=i)swap(a[min],a[i]);
    }
    for(i=0;i<10;i++)printf("%d ",a[i]);
}
int main(void)
{
    fun3();
    return 0;
}