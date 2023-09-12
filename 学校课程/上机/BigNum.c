//大数计算
#include <stdio.h>
#include <string.h>
#define SIZE 500
void mul(char *a, char *b, int s1, int s2) //a数组地址，b数组地址，a数组长度，b数组长度
{
    int c[2 * SIZE] = {0}, i, j;
    for (i = 0; i < s1; i++) //两数相乘，但是先不进位
    {
        for (j = 0; j < s2; j++)
            c[i + j + 1] += (a[i] - '0') * (b[j] - '0'); //+1是为了给进位预留一个位置
    }
    for (i = s1 + s2 - 1; i; i--) //进位。一个s1位数 乘以 一个s2位数，
    {                             //如果不进位，那结果是一个 s1+s2-1位数，
        c[i - 1] += c[i] / 10;    //进位的话，就是一个 s1+s2位数
        c[i] %= 10;               //本程序默认给进位预留了一个位置，所以进位与否，结果的最后那位数的位置一直都是s1+s2
    }
    i = c[i] ? 0 : 1;
    while (i < s1 + s2)
        printf("%d", c[i++]);
    putchar('\n');
    return;
}
int main(void)
{
    char a[SIZE], b[SIZE];
    scanf("%s%s", a, b);
    mul(a, b, strlen(a), strlen(b));
}