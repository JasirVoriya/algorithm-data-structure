// 问题 D: 求逆序数
// 描述
// 在一个排列中，如果一对数的前后位置与大小顺序相反，即前面的数大于后面的数，那么它们就称为一个逆序。一个排列中逆序的总数就称为这个排列的逆序数。

// 现在，给你一个N个元素的序列，请你判断出它的逆序数是多少。

// 比如 1 3 2 的逆序数就是1。

// 格式
// 输入格式
// 第一行输入一个整数T表示测试数据的组数（1<=T<=5)
// 每组测试数据的每一行是一个整数N表示数列中共有N个元素（2〈=N〈=100000）
// 随后的一行共有N个整数Ai(0<=Ai<1000000000)，表示数列中的所有元素。

// 数据保证在多组测试数据中，多于10万个数的测试数据最多只有一组。

// 输出格式
// 输出该数列的逆序数

// 样例
// 样例输入 Copy
// 2
// 2
// 1 1
// 3
// 1 3 2
// 样例输出 Copy
// 0
// 1
#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
const int MAX_N = 1e5 + 10;
ll arr[MAX_N];
int ans;
void marge(ll* arr1, int size1, ll* arr2, int size2)
{
    ll* temps = (ll*)malloc(sizeof(ll) * (size1 + size2));
    int index=0,i=0,j=0;
    while(i<size1&&j<size2){
        
    }
}
void sort(ll* a, int n)
{
    if (n <= 1)
        return;
    sort(a, n / 2);
    sort(a + n / 2, (n + 1) / 2);
    marge(a, n / 2, a + n / 2, (n + 1) / 2);
}
int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        ans = 0;
        sort(arr, n);
        printf("%d\n", ans);
    }
    return 0;
}