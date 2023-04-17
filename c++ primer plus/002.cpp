#include<iostream>
#include<cstring>
using namespace std;
int main(void)
{
    const int ArSize=20;
    char name[ArSize],ch;
    cin.get(name, ArSize).get(ch);  
    cin.getline(name,ArSize);
    //cin.get(name,ArSize) 不会读取 输入队列 里面的 换行符，但会在字符串最后加上 空字符
    //cin.getline(name,ArSize) 会读取 输入队列 里面的 换行符，并把它替换成 换行符
    //cin.get()可以用来检查停止读取的原因，如果 ch变量 中存的是 换行符，
    //说明已经读取了整行，否则就是因为数组已经满了
    return 0;
}