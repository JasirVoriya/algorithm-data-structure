#include <iostream>
#include <string>
using namespace std;
int words(string str)
{
    int count = 0;
    int i = 0, size = str.size();
    while (i < size)
    {
        while (str[i] == ' ' && i < size)
            i++;
        if (i < size)
            count++;
        while (str[i] != ' ' && i < size)
            i++;
    }
    return count;
}
class complex
{
private:
    int x, y;

public:
    complex(int x = 0, int y = 0)
    {
        this->x = x, this->y = y;
    }
    complex operator+(const complex &a)
    {
        this->x += a.x, this->y += a.y;
        return *this;
    }
    complex operator+=(const complex &a)
    {
        this->x += a.x, this->y += a.y;
        return *this;
    }
    void add(int x, int y)
    {
        this->x += x, this->y += y;
    }
    void print()
    {
        cout << "(" << x << ", " << y << "i)" << endl;
    }
};
class Class
{
private:
    static const int maxn = 6;
    class
    {
    public:
        string id, name;
        double subj1, subj2, subj3, avg;
        void print()
        {
            cout << "学号：" << id << endl;
            cout << "姓名:" << name << endl;
            cout << "第一门成绩：" << subj1 << endl;
            cout << "第二门成绩：" << subj2 << endl;
            cout << "第三门成绩：" << subj3 << endl;
            cout << "平均成绩：" << avg << endl;
        }
    } student[maxn];

public:
    Class()
    {
        for (int i = 0; i < maxn; i++)
        {
            cout << "输入第" << i + 1 << "个同学的学号：", cin >> student[i].id;
            cout << "输入第" << i + 1 << "个同学的姓名：", cin >> student[i].name;
            cout << "输入第" << i + 1 << "个同学的第一门成绩：", cin >> student[i].subj1;
            cout << "输入第" << i + 1 << "个同学的第二门成绩：", cin >> student[i].subj2;
            cout << "输入第" << i + 1 << "个同学的第三门成绩：", cin >> student[i].subj3;
            student[i].avg = (student[i].subj1 + student[i].subj2 + student[i].subj3) / 3;
        }
    }
    auto top()
    {
        int index = 0;
        for (int i = 1; i < maxn; i++)
        {
            if (student[index].avg < student[i].avg)
                index = i;
        }
        return student[index];
    }
};
int main(void)
{
    //统计单词个数
    cout << words("1 2 3") << endl;
    //复数类
    complex a(1, 2), b(3, 4);
    a.print(), b.print();
    a += b;
    a.print();
    a.add(5, 6);
    a.print();
    //班级类
    Class No1;
    cout << "平均成绩最高的同学：" << endl;
    No1.top().print();
}