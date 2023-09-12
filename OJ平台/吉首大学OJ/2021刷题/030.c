/*
问题 G: 竞选主席
描述
又来到了四年一度的主席竞选大赛，然后有n个候选人，编号分别是从1-n，现在需要你统计出票数最多的候选人是谁

格式
输入格式
输入n

然后依次是n行

下面第几行就代表第几个候选人的票数

输出格式
输出最多票数的候选人编号以及票数

样例
样例输入 Copy
5
98765
12365
87954
1022356
985678
样例输出 Copy
4
1022356		
提示
票数可能会达到100位数字

n<=20
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    freopen("input.txt", "r", stdin);
    char A[200], B[200];
    int n, i, max;
    scanf("%d", &n), getchar();
    scanf("%s",A), getchar(),max = 1;
    for (i = 2; i <= n; i++)
    {
        scanf("%s",B),getchar();
        if (strlen(A) > strlen(B))
            continue; //比最大值位数小直接pass
        if (strlen(A) < strlen(B) || strcmp(A, B) < 0)
            strcpy(A, B), max = i;
    }
    printf("%d\n%s\n", max, A);
}