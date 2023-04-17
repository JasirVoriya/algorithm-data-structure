#include<iostream>
#include<string>
using namespace std;
int main(void)
{
    const int ArSize = 20;
    char chars[ArSize];
    cin.getline(chars,ArSize);
    cout << "chars:" << chars << endl;

    string str;
    getline(cin,str);//string对象 读取一行的方式和 字符串数组不同
    cout << "str:" << str << endl;
    return 0;
} 