#include<iostream>
using namespace std;
int main(void)
{
    char ch;
    cin.get(ch);
    while(ch!='.')
    {
        if(ch=='\n')cout<<ch;
        else cout<<++ch;//将++ch改成ch+1，会发生有趣的事情呢 (^V^)
        cin.get(ch);
    }
    return 0;
}