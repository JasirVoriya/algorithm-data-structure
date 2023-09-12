#include <stdio.h>
#define mod 1000000009
#define size 10100
typedef unsigned long long ull;
ull array[size] = {0, 1, 2};
void init(void)
{
    for (int i = 3; i < size; i++)
    {
        array[i] = 1;
        for (int j = 1; j < i; j++)
            array[i] = (array[i] + array[j]) % mod;
    }
}
int main(void)
{
    init();
    int n;
    while (~scanf("%d", &n))
    {
        printf("%llu\n", array[n]);
    }
}