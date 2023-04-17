#include <iostream>
#include <set>
using namespace std;
int prime[2000], num;
bool notprime[10000] = {true, true};
void init()
{
    int i = 2;
    while (i < 10000)
    {
        for (int j = 2 * i; j < 10000; j += i)
            notprime[j] = true;
        i++;
        while (i < 10000 && notprime[i])
            i++;
    }
    for (int i = 1000; i < 10000; i++)
        if (notprime[i] == false)
            prime[num++] = i;
}
int difference(int a, int b)
{
    int n = 0;
    while (a)
    {
        if (a % 10 != b % 10)
            n++;
        a /= 10, b /= 10;
    }
    return n;
}
int main(void)
{
    init(); //打表，把四位数的素数都存在prime数组里面
    int n;
    cin >> n;
    while (n--)
    {
        set<int> step[50]; //用来存遍历结果
        int a, b;
        cin >> a >> b;
        step[0].insert(a);
        if (step[0].count(b))
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i < 50; i++)
        {
            for (set<int>::iterator it = step[i - 1].begin(); it != step[i - 1].end(); it++)
            {                                 //根据上一步的数据，来计算后面的结果
                for (int j = 0; j < num; j++) //遍历素数表
                {
                    if (difference(*it, prime[j]) == 1) //如果两个四位素数只有一位不相同
                    {
                        step[i].insert(prime[j]); //存起来
                    }
                }
            }
            if (step[i].count(b)) //如果得到了结果
            {
                cout << i << endl; //输出结果
                break;
            }
        }
    }
    return 0;
}