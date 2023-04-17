/*
问题 G: 摘陶陶(JSU-ZJJ)
描述
话说去年苹果们被陶陶摘下来后都很生气，于是就用最先进的克隆技术把陶陶克隆了好多份> .< 然后把他们挂在树上，准备摘取。 摘取的规则是，一个苹果只能摘一个陶陶，且只能在它所能摘到的高度以下的陶陶，陶陶高度为0时，不能摘取，如果摘不到的话只能灰溜溜的走开了> .< 给出苹果数目及每个苹果可以够到的高度和各个陶陶的高度，求苹果们都摘完后剩下多少个陶陶……

格式
输入格式
第一行为两个数，分别为苹果的数量n和陶陶的数量m（n,m< =2000） 以下的n行，分别为各个苹果能够到的最大高度。 再接下来的m行，分别为各个陶陶的高度。 高度均不高于300。 当然了，摘取的顺序按照输入的“苹果够到的最大高度”的顺序来摘。

输出格式
输出仅有一个数，是剩下的陶陶的数量

样例
样例输入 Copy
5 5
9
10
2
3
1
6
7
8
9
10
样例输出 Copy
3
		
提示
很容易的基础题哦> .<
*/
#include <stdio.h>
#include <stdlib.h>
void sort(int *a, int n)
{
    int i, j, t;
    for (i = 1; i < n; i++)
    {
        t = a[i];
        for (j = i - 1; a[j] < t && j >= 0; j--)
            a[j + 1] = a[j];
        a[j + 1] = t;
    }
}
int main(void)
{
    int *a, *b, n, m, i, j, k;
    scanf("%d%d", &n, &m);
    a = (int *)malloc(sizeof(int) * n);
    b = (int *)malloc(sizeof(int) * m);
    for (i = 0; i < n; i++)
        scanf("%d", a + i); //输入苹果
    for (i = 0; i < m; i++)
        scanf("%d", b + i); //输入陶陶
    sort(a, n), sort(b, m); //对苹果和陶陶排序
    for (i = k = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (!b[j])
                continue;
            if (a[i] > b[j])
            {
                b[j] = 0, k++;
                break;
            }
        }
        if (j == m)
            break;
    }
    printf("%d", m - k);
    free(a), free(b);
}