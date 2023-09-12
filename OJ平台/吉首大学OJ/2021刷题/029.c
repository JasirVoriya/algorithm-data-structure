/*
问题 G: 密码(JSU-ZJJ)
描述
网上流传一句话:"常在网上飘啊，哪能不挨刀啊～"。其实要想能安安心心地上网其实也不难，学点安全知识就可以。

首先，我们就要设置一个安全的密码。那什么样的密码才叫安全的呢？一般来说一个比较安全的密码至少应该满足下面两个条件：

(1).密码长度大于等于8，且不要超过16。
(2).密码中的字符应该来自下面“字符类别”中四组中的至少三组。

这四个字符类别分别为：
1.大写字母：A,B,C...Z;
2.小写字母：a,b,c...z;
3.数字：0,1,2...9;
4.特殊符号：~,!,@,#,$,%,^,&;

给你一个密码，你的任务就是判断它是不是一个安全的密码。

格式
输入格式
输入数据第一行包含一个数M，接下有M行，每行一个密码（长度最大可能为50），密码仅包括上面的四类字符。

输出格式
对于每个测试实例，判断这个密码是不是一个安全的密码，是的话输出YES，否则输出NO。

样例
样例输入 Copy
3
a1b2c3d4
Linle@ACM
^~^@^@!%
样例输出 Copy
NO
YES
NO
*/
#include <stdio.h>
#include <string.h>
int islower(int ch)
{
    return ch >= 'a' && ch <= 'z';
}
int issupper(int ch)
{
    return ch >= 'A' && ch <= 'Z';
}
int islnum(int ch)
{
    return ch >= '0' && ch <= '9';
}
int issign(int ch)
{
    return ch =='!'|| ch =='^'|| ch =='%'|| ch =='$'|| ch =='#'|| ch =='@'|| ch =='~'||ch=='&';
}
int main(void)
{
    char str[51], a[4];
    int n, i,k;
    scanf("%d", &n), getchar();
    while (n--)
    {
        k=0;
        gets(str);
        a[0]=a[1]=a[2]=a[3]=0;
        if (strlen(str) < 8 || strlen(str) > 16)
        {
            puts("NO");
            continue;
        }
        for (i = 0; str[i]; i++)
        {
            if(islnum(str[i]))a[0]=1;
            else if(islower(str[i]))a[1]=1;
            else if(issupper(str[i]))a[2]=1;
            else if(issign(str[i]))a[3]=1;
            else {
                puts("NO");
                k=1;
                break;
            }
        }
        if(k==1)continue;
        if(!str[i]&&(a[0]+a[1]+a[2]+a[3])>=3)puts("YES");
        else puts("NO");
    }
}