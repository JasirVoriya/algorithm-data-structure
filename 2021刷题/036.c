/*
问题 I: 串的处理
描述
在实际的开发工作中，对字符串的处理是最常见的编程任务。本题目即是要求程序对用户输入的串进行处理。具体规则如下：
1.	把每个单词的首字母变为大写。
2.	把数字与字母之间用下划线字符（_）分开，使得更清晰
3.	把单词中间有多个空格的调整为1个空格。
我们假设：用户输入的串中只有小写字母，空格和数字，不含其它的字母或符号。每个单词间由1个或多个空格分隔。
假设用户输入的串长度不超过200个字符。
格式
输入格式
例如：
用户输入：
you and     me what  cpp2005program
用户输入：
this is     a      99cat
输出格式
则程序输出：
You And Me What Cpp_2005_program
则程序输出：
This Is A 99_cat
样例
样例输入 Copy
you and     me what  cpp2005program
this is     a      99cat
样例输出 Copy
You And Me What Cpp_2005_program
This Is A 99_cat
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int moveleft(char *str1, char *str2)
{
    while (*str2)
    {
        *str1 = *str2;
        str1++, str2++;
    }
    *str1 = *str2;
    return str2 - str1;
}
int moveright(char *str1, int n)
{
    char *str2 = str1 + strlen(str1);
    while (str2 >= str1)
    {
        str2[n] = str2[0];
        str2--;
    }
    return n;
}
char *format(char *str)
{
    int i = 0, k = 0;
    while (str[i])
    {
        while (str[i] && str[i] == ' ') //跳空格
            i++;
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i -= moveleft(str + k, str + i);
        while (str[i] && str[i] != ' ') //跳单词
            i++;
        k = i + 1;
    }
    if (str[i - 1] == ' ')
        str[i - 1] = '\0';
    return str;
}
char *format2(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (isalpha(str[i - 1]))
            {
                moveright(str + i, 1);
                str[i] = '_';
                i++;
            }
            if (isalpha(str[i + 1]))
            {
                moveright(str + i + 1, 1);
                str[i + 1] = '_';
                i++;
            }
        }
        i++;
    }
    return str;
}
int main(void)
{
    char str[201];
    while(gets(str)!=NULL)
    puts(format2(format(str)));
    return 0;
}