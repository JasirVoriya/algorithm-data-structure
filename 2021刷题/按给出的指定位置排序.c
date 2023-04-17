#include <stdio.h>
void sort(int *a, int end)
{
    for (int i = 1; i < end; i++)
    {
        int t = a[i], j;
        for (j = i - 1; j >= 0 && a[j] < t; j--)
            a[j + 1] = a[j];
        a[j + 1] = t;
    }
}
int main(void)
{
    int a[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", a + i), getchar();
    int begin, end;
    scanf(" m :%d\nn : %d", &begin, &end);
    sort(a + begin, end);
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return 0;
}