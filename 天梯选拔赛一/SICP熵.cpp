#include <bits/stdc++.h>
using namespace std;
void Union(int* a,int len1,int* b,int len2)
{
    
}
void Sort(int *a, int size)
{
    if (size <= 1)
        return;
    int l = 0, r = size - 1, mid = (l + r) / 2;
    Sort(a, mid);
    Sort(a + mid, size - mid);
    Union(a, mid, a + mid, size - mid);
}
int main(void)
{

    return 0;
}