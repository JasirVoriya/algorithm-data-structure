#include <stdio.h>
#include <string.h>
int memory[10100];
int fun(int a, int b, int c)
{
    if (c == 0)
        return 1;
    if (c < 0)
        return 0;
    if (memory[c] != -1)
        return memory[c];
    return memory[c] = fun(a, b, c - a) || fun(a, b, c - b);
}
int main(void)
{
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c))
    {
        memset(memory, -1, sizeof(memory));
        if (fun(a, b, c))
            puts("Yes");
        else
            puts("No");
    }
}