#include <stdio.h>
#define max(x, y) (x > y ? x : y)
int main(void)
{
    unsigned int n;
    while (~scanf("%u", &n)) {
        float index;
        unsigned int ans = 0;
        unsigned int arry[20100] = { 0 };
        for (int i = 0; i < n; i++) {
            scanf("%f", &index);
            int x = index * 100;
            x += 10000;
            arry[x]++;
            ans = max(ans, arry[x]);
        }
        printf("%u\n", ans);
    }
}