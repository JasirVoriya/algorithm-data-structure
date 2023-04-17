#include <stdio.h>
#define maxn 15
int ans, count;
void fun(bool a[][maxn], int N, int n)
{
    int i, j;
    if (n == N)
    {
        for (i = 0; i < N; i++)
        {
            printf("* ");
            for (j = 0; j < N; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
        printf("\n");
        ans++;
        return;
    }
    for (i = 0; i < N; i++) //遍历列
    {
        for (j = 1; j <= n; j++) //遍历行
        {
            count++;
            //一行只放一个皇后,所以不需要判断行
            if (a[n - j][i] == true) //判断第i列有没有皇后,只需要判断[0,n]行的列,因为我们只放到了第n行
                break;
            if (i >= j && a[n - j][i - j] == true) //判断a[n][i]左上角方向有没有皇后
                break;
            if (i + j < N && a[n - j][i + j] == true) //判断a[n][i]右上角方向有没有皇后
                break;
        }
        if (j == n + 1) //如果a[n][i]所在的列、左右上角方向，都没有皇后
        {
            a[n][i] = true;   //就可以在a[n][i]的位置放一个皇后
            fun(a, N, n + 1); //然后开始放n+1行的皇后
            a[n][i] = false;  //回溯的时候，再把n行的皇后拿掉
        }
    }
    return;
}

int main(void)
{
    freopen("output2.txt", "w", stdout);
    int answer[11];
    for (int i = 1; i <= 10; i++)
    {
        printf("N=%d:\n", i);
        bool a[maxn][maxn] = {false};
        ans = 0;
        fun(a, i, 0);
        answer[i] = ans;
        printf("%d种\n\n", ans);
    }
    // int N;
    // while (scanf("%d", &N) != EOF)
    // {
    //     if (N <= 0)
    //         break;
    //     printf("%d\n", answer[N]);
    // }
}
