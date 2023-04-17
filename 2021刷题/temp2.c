/*
问题 F: 周老师的区间问题
描述
周老师无聊时乱写了 n 个区间，但处女座的他随后又想将 n 个区间整理合并，但他发现区间太多了，于是他想请你帮帮他

格式
输入格式
每次测试输入多组数据（小于100组），对于每组输入数据:

第一行为  n ，代表 n 个区间

接下来 n 行，每行两个数 s , t 代表区间 [s,t]

0 < n < 15000

0 <= s <= t < 10000000 

输出格式
第一行输出一个数字 q ，代表合并后剩余的区间个数

随后 q 行 按从小到大的顺序输出区间

样例
样例输入 Copy
3
2 4
1 3
7 7
样例输出 Copy
2
1 4
7 7
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int left, right;
} node;
void sort(node *a, int n)
{
    int i, j;
    node t;
    for (i = 1; i < n; i++)
    {
        t = a[i];
        for (j = i - 1; j >= 0 && a[j].left > t.left; j--)
            a[j + 1] = a[j];
        a[j + 1] = t;
    }
}
int main(void)
{
    node *ptr;
    int t, i, j, n, s;
    scanf("%d", &n);
        ptr = (node *)malloc(sizeof(node) * n);
    for (i = 0; i < n; i++)
        scanf("%d%d", &ptr[i].left, &ptr[i].right);
    sort(ptr, n);
    for (i = s = 0; i < n; i = j + 1)
    {
        ptr[s].left = ptr[i].left;
        for (j = i; j < n - 1 && ptr[j].right >= ptr[j + 1].left; j++)
            ;
        ptr[s].right = ptr[j].right;
        s++;
    }
    printf("%d\n", s);
    for (i = 0; i < s; i++)
    {
        printf("%d %d\n", ptr[i].left, ptr[i].right);
    }
    free(ptr);
}