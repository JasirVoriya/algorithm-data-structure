/*
问题 C: [USACO 1.1.1]你要乘坐的飞碟在这里
描述
一个众所周知的事实，在每一慧星后面是一个不明飞行物UFO。 这些不明
飞行物时常来收集来自在地球上忠诚的支持者。 不幸地，他们的空间在每
次旅行只能带上一群支持者。 他们要做的是用一种聪明的方案让每一个
团体人被慧星带走。 他们为每个慧星起了一个名字，通过这些名字来决定
一个团体是不是特定的慧星带走。 那个相配方案的细节在下面被给出； 
你的工作要写一个程序来通过团体的名字和彗星的名字来决定一个组是否
应该与在那一颗慧星后面的不明飞行物搭配。团体的名字和慧星的名字都
以下列各项方式转换成一个数字: 这个最后的数字代表名字中所有字母的
信息，"A" 是 1 和 "Z" 是 26。举例来说，团体 "USACO" 会是 21*19*1*3*15=17955 。
 如果团体的数字 mod 47 等于慧星的数字 mod 47,那么你要告诉这个团体准备好被带走 
 ! 写一个程序读入慧星的名字和团体的名字，如果搭配打印"GO"否者打印"STAY" 团体的
 名字和慧星的名字将会是没有空格或标点的一串大写字母（不超过6个字母）

格式
输入格式
第 1 行: 彗星的名字（一个长度为1到6的字符串） 第 2 行: 团体的名字（一个长度为1到6的字符串）

输出格式
单独一行包含"STAY"或"GO".

样例
样例输入 Copy
COMETQ
HVNGAT
样例输出 Copy
GO
*/
#include<stdio.h>
int main(void)
{
    //freopen("input.txt","r",stdin);
    char str1[7],str2[7];
    int s1,s2,i;
    gets(str1),gets(str2);
    for(s1=1,i=0;str1[i];i++)
    {
        s1*=str1[i]-'A'+1;
        s1%=47;
    }
    for(s2=1,i=0;str2[i];i++)
    {
        s2*=str2[i]-'A'+1;
        s2%=47;
    }
    if(s1==s2)puts("GO");
    else puts("STAY");
}
