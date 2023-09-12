#include<stdio.h>
#include<string.h>
int fun(const char* str)
{
    int ans=0;
    for(int i=0;str[i];i++)ans=(ans<<1)+str[i]-'0';
    return ans;
}
int main(void)
{
    int t;
    char str[10];
    scanf("%d",&t),getchar();
    while(t--)
    printf("%c",fun(gets(str)));
    return 0;
}