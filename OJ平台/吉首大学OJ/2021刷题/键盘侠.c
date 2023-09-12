#include <stdio.h>
int index[26][3]={
    {'A',2,1},{'B',3,5},{'C',3,3},{'D',2,3},{'E',1,3},{'F',2,4},{'G',2,5},
    {'H',2,6},{'I',1,8},{'J',2,7},{'K',2,8},{'L',2,9},{'M',3,7},{'N',3,6},
    {'O',1,9},{'P',1,10},{'Q',1,1},{'R',1,4},{'S',2,2},{'T',1,5},{'U',1,7},
    {'V',3,4},{'W',1,2},{'X',3,2},{'Y',1,6},{'Z',3,1}
};
int main()
{
    int ch;
    while((ch=getchar())!=EOF)
    {
        getchar();
        ch-='A';
        if(ch<15)printf("%d\n",ch/3+2);
        else
        {
            ch-=15;
            if(ch<4)puts("7");
            else if(ch<7)puts("8");
            else puts("9");
            ch+=15;
        }
        printf("%d %d\n",index[ch][1],index[ch][2]);
    }
    return 0;
}