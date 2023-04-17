#include <stdio.h>
int main(void)
{
    char ch1,ch2,str[123];
    scanf("%c\n%c%s",&ch1,&ch2,str);
    printf("%c#%c#%s",ch1,ch2,str);
    scanf("%d");
    getchar();
    scanf("%c");
    getchar();
    //puts(str);
    return 0;
}
//"%s" 是以空白字符结束输入
//"%d" 是以空白字符结束输入
//scanf("%c %c%s");
//空白字符 space tab enter
//5\n10\n
///111\n
//    1111 
//12345
//
//
//10    10/2=5
//1010  1010/2=101