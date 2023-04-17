#include <stdio.h>
void fun(char *a, char *b, int size) //先序序列，后序序列，序列长度
{
    if (size <= 0)
        return;
    putchar(*(b + size - 1)); //输出父节点
    putchar(' ');
    char *it = a; //在先序序列里面找到父节点
    int count = 0;
    while (a[count] != b[size - 1])
        count++;                                     //计算左子树的节点数
    fun(a, b, count);                                //递归左子树
    fun(a + count + 1, b + count, size - count - 1); //递归右子树
}
char a[10000] = {0};
int main(void)
{
    int i = 0;
    while (scanf("%s", a + i) != EOF)
        i++;
    fun(a, a + i / 2, i / 2);
    return 0;
}