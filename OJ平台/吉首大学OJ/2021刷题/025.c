/*

问题 D: Jack的字符串问题
描述
阿操最讨厌写字符串的题目，看到眼前密密麻麻的字母就烦。这件事的起因就是很久很久以前的一次找重复字符的位置。 现在有一个字符串，我们要找出其中的重复的字符并输出这些字符和字符的位置，如：aabcaabc22 输出 a，0；a，1；a，4；a，5，b，2；b，6，c，3；c，7；2，8；2，9
格式
输入格式
输入一个字符串（字符串中只含数字和字母）。其长度不超过100。

输出格式
根据样例的格式将重复出现的字符位置输出

样例
样例输入 Copy
aabcaabc22
样例输出 Copy
a:0,a:1,a:4,a:5
b:2,b:6
c:3,c:7 
2:8,2:9
*/
#include<stdio.h>
int main(void)
{
    freopen("input.txt","r",stdin);
    char str[101],ch,i,j;
    while(gets(str)) while(1)
    {
        for(i=0;str[i]&&str[i]=='#';i++);//跳过排出的字符
        if(!str[i])break;//空串结束
        j=i,ch=str[i],str[i]='#';//排除
        for(i++;str[i]&&str[i]!=ch;i++);
        if(str[i]==ch)
        {
            printf("%c:%d", ch, j);
            while (str[i])
            {
                if (str[i] == ch)
                {
                    str[i] = '#';
                    printf(",%c:%d", ch, i);
                }
                i++;
            }
            printf("\n");
        }
    }    
    return 0;
}