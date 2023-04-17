/*
问题 J: 字符串操作一（串）
描述
输入一长度为n的字符串，若其n为偶数，则将字符串从中间反转，若为奇数，则将前后各(n-1)/2个字符反转，中间字符不动。

格式
输入格式
输入有多组，每行有一个字符串

输出格式
对应每行输出反转后的字符串

样例
样例输入 Copy
asdfghjkl

qwerty
样例输出 Copy
fdsaglkjh

ewqytr
*/
#include<stdio.h>
#include<string.h>
int main(void)
{
    char str[1000];
    int i,len;
    while(gets(str))
    {
        len=strlen(str);
        for(i=len/2-1;i>=0;i--)putchar(str[i]);
        i = len / 2-1;
        if(len%2) putchar(str[len/2]),i++;
        for(len--;len>i;len--) putchar(str[len]);
        putchar('\n');
    }
}