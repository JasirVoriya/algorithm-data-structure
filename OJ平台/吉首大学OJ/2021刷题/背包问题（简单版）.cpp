#include <stdio.h>
#include <stdlib.h>
const int size = 50000;
struct obj
{
    float weight, value, price;
};
int cmp(const void *x, const void *y)
{

    return ((obj *)y)->price - ((obj *)x)->price < 0 ? -1 : 1;
}
obj a[size];
void input(int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%f%f", &a[i].weight, &a[i].value);
        a[i].price = a[i].value / a[i].weight;
    }
    return;
}
float solve(int n, int c)
{
    if (n == 0 || c == 0)
        return 0;
    qsort(a, n, sizeof(obj), cmp);
    float total = 0, weight = 0;
    int i;
    for (i = 0; weight <= c; i++)
    {
        total += a[i].value;
        weight += a[i].weight;
    }
    i--;
    weight -= c;
    total -= weight * a[i].price;
    total = (int)(total * 100) * 1.0 / 100;
    return total;
}
int main(void)
{
    int n, c;
    scanf("%d%d", &n, &c);
    input(n);
    printf("%.2f", solve(n, c));
    return 0;
}