#include <iostream>
//#include <ostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("input.txt"); // 输入文件
	ofstream fout("output.txt"); //输出文件
	streambuf *cinbackup;
	streambuf *coutbackup;
	cinbackup = cin.rdbuf(fin.rdbuf()); //用 rdbuf() 重新定向，返回旧缓冲区指针
	coutbackup = cout.rdbuf(fout.rdbuf()); //用 rdbuf() 重新定向，返回旧缓冲区指针
 
	char a[100];
	cin >> a; //从input.txt文件读入
	cout << a << endl; //写入 output.txt
 
	//还原标准输入输出流
	cin.rdbuf(cinbackup); // 取消，恢复键盘输入
	cout.rdbuf(coutbackup); //取消，恢复屏幕输出
 
	fin.close();//随手关闭
	fout.close();//是好习惯
 
	return 0;
}