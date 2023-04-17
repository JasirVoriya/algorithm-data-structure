#include <bits/stdc++.h>
using namespace std;
void solove(unsigned int x)
{
    int y = x;
    char ans[32] = {0};
    int index = 31;
    while (x)
    {
        ans[index--] = x & 1;
        x >>= 1;
    }
    int i = 0;
    while (i < 32)
    {
        printf("%d", ans[i]);
        i++;
        if (i % 8 == 0)
            putchar(' ');
    }
    printf("<->%d\n", y);
}
int main(void)
{
    int x;
    while(cin>>x)
    {
        solove(x);
    }
    return 0;
}