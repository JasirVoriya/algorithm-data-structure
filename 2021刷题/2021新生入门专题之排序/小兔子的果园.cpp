#include <stdio.h>
void sort(int a[], int n, bool (*cmp)(int, int))
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < n - i; j++) {
            if (cmp(a[j], a[j + 1]) == false) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j] = temp;
            }
        }
    }
}
const int MAX_N = 50;
int main()
{
    int n, a[MAX_N][5] = { 0 }, sum[MAX_N] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
            sum[i] += a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < n - i; j++) {
            // 按芒果的数量从大到小排序，如果芒果的数量相同，那就按照其他水果的总数量从小到大排序。
            if (a[j][1] < a[j + 1][1] || a[j][1] == a[j + 1][1] && sum[j] > sum[j + 1]) {
                int temp = sum[j];
                sum[j] = sum[j + 1];
                sum[j + 1] = temp;
                for (int k = 0; k < 5; k++) {
                    temp = a[j][k];
                    a[j][k] = a[j + 1][k];
                    a[j + 1][k] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}