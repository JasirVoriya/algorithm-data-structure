/*
问题 U: I still love you very much!
描述
等一个喜欢的人，需要多久？

有佛祖弟子阿难，曾愿化身石桥，
受五百年风吹，五百年日晒，五百年雨打，
但求一少女从桥上经过。 


忘一个喜欢的人，又需要多久？ 


你的好友一直想对一个女孩说"I still love you very much!",可出于某种原因，他想将这句话发到网上，好让她看见。可你的好友又怕太多人知道这句话的意思， 
于是他便想将这句话中的每一个字符所对应的int值转换为二进制，二进制不足8位的在前面补0，比如字符'I'所对应的int值为73，所对应的二进制为01001001. 

格式
输入格式
输入一个可能带空格的字符串s，1<=strlen(s)<=1000

输出格式
将该字符串中的每个字符换成二进制，每个二进制占一行。

样例
样例输入 Copy
I still love you very much!
样例输出 Copy
01001001
00100000
01110011
01110100
01101001
01101100
01101100
00100000
01101100
01101111
01110110
01100101
00100000
01111001
01101111
01110101
00100000
01110110
01100101
01110010
01111001
00100000
01101101
01110101
01100011
01101000
00100001		
提示
多组输入
*/
#include <stdio.h>
void fun(unsigned char ch)
{
    char str[9] = {"00000000"}, i = 7;
    while (ch)
    {
        str[i--] = ch % 2 + '0';
        ch /= 2;
    }
    puts(str);
}
int main(void)
{
#ifdef ONLINE_JDUGE
    freopen("input.txt", "r", stdin);
#endif
    char ch;
    while (((ch = getchar()) != EOF))
    {
        if(ch=='\n')continue;
        fun(ch);
    }
}