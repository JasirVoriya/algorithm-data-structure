#include<stdio.h>
#include<ctype.h>
int main(void)
{
    int count[256]={0};
    int ch;
    while((ch=getchar())!='\n')
        count[toupper(ch)]++;
    while (count['G']||count['P']||count['L']||count['T'])
    {
        if(count['G'])putchar('G'),count['G']--;
        if(count['P'])putchar('P'),count['P']--;
        if(count['L'])putchar('L'),count['L']--;
        if(count['T'])putchar('T'),count['T']--;
    }   
}