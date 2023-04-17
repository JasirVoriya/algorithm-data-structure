#include <stdio.h>
#include <math.h>
long long a[10];
void sort(long long *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        long long t = a[i], j = i - 1;
        while (j >= 0 && a[j] < t)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
}
int main(void)
{
    while (1)
    {
        for (int i = 0; i < 10; i++)
            if(scanf("%lld", a + i)==EOF)
                return 0;
        sort(a, 10);
        long long add = a[0] + a[1];
        long long mul = a[0] * a[1] > a[8] * a[9] ? a[0] * a[1] : a[8] * a[9];
        printf("%lld %lld\n", add, mul);
    }
    return 0;
}