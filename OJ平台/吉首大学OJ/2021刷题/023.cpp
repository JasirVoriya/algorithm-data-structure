/*
问题 K: 小学生分数计算
描述
分数的计算想必各位学弟学妹都会吧，现在要求你写一个程序来实现小学分数的加减法计算。给出2个分数，求他们的结果。

格式
输入格式
输入包含多行数据
每行数据是一个字符串，格式是"a/boc/d"。
其中a, b, c, d是一个0-9的整数。o是运算符"+"或者"-"。
数据以EOF结束
输入数据保证合法

输出格式
对于输入数据的每一行输出两个分数的运算结果。
注意结果应符合书写习惯，没有多余的符号、分子、分母，并且化简至最简分数

样例
样例输入 Copy
1/8+3/8
1/4-1/2
1/3-1/3
样例输出 Copy
1/2
-1/4
0
*/
#include <stdio.h>
int fun(int a, int b)  // a和b的最大公约数
{
  int r = a % b;
  while (r) {
    a = b, b = r;
    r = a % b;
  }
  return b;
}
void func(int x1, int y1, int x2, int y2)  //约分
{
  if (y1 == 0 || y2 == 0) return;
  x1 *= y2, x2 *= y1;
  x1 += x2, y1 *= y2;  //通分相加
  if (!x1) {
    puts("0");
    return;
  }
  int t = fun(x1, y1);
  x1 /= t, y1 /= t;
  if (y1 < 0) x1 *= -1, y1 *= -1;
  if (y1 == 1) {
    printf("%d\n", x1);
    return;
  }
  printf("%d/%d\n", x1, y1);
}
int main(void) {
  int x1, y1, x2, y2;
  while (~scanf("%d/%d%d/%d", &x1, &y1, &x2, &y2)) func(x1, y1, x2, y2);
}
