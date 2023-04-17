#include <stdio.h>
// 数组
int main(void) {
    int a[5];
    // 数组下标从0开始
    // 最后一个元素是a[3]，但是我们访问了a[4]，有什么问题？
    for (int i = 1; i <= 4; i++) {
        scanf("%d", &a[i]);
    }
    int max = 0;
    int i = 1;  //定义变量，不给初值，它的值是随机的
    while (i < 4) {
        if (a[i] > a[max]) max = i;
        i++;
    }
    printf("%d\n", max + 1);
    return 0;
}