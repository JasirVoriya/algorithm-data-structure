#include<stdio.h>
char str1[10000],str2[10000],str3[30000];
int main(void)
{
    gets(str1),gets(str2);
    int i=0,j=0,k=0;
    while(str1[i]&&str2[j])
    {
        str3[k++]=str1[i++];
        str3[k++]=str2[j++];
    }
    while(str1[i])str3[k++]=str1[i++];
    while(str2[j])str3[k++]=str2[j++];
    puts(str3);
    return 0;
}