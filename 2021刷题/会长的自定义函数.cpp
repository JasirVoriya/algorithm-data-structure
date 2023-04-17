#include<stdio.h>
#include<string.h>
int main(void)
{
    int t;
    char str[200];
    scanf("%d",&t),getchar();
    while(t--)
    {
        gets(str);
        printf("%d\n",strlen(str));
    }
}