#include <stdio.h>
void search(int *array, int n, int *pmax, int *pindex)
{
    int *begin = array, *end = array + n;
    *pmax = *begin,*pindex=0;
    for (int *it = begin + 1; it < end; it++)
    {
        if (*it > *pmax)
        {
            *pmax = *it;
            *pindex=it-begin;
        }
    }
    return;
}
int main(void)
{
    int a[] = {1, 5, 2, 3, 11, 55, 22, 98, 123, 5};
    int max, index;
    search(a, sizeof(a) / sizeof(int), &max, &index);
    printf("max:%d -> %d\n", max, index);
    return 0;
}