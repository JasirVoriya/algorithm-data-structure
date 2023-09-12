#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
void solove(char *a, char *b, int size = 0) //先序、中序
{
    if (size <= 0)
        return;
    int index = 0;
    while (a[0] != b[index])
        index++;
    solove(a + 1, b, index);                                //递归左子树
    solove(a + 1 + index, b + index + 1, size - index - 1); //递归右子树
    putchar(a[0]);
}
int main(void)
{
    int n;
    cin >> n;
    char str1[maxn], str2[maxn];
    cin >> str1 >> str2;
    solove(str1, str2, n);
    return 0;
}