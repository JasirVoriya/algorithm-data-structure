#include <iostream>
#include <fstream>
#include<cstdio>
using namespace std;
const int SIZE = 1000001;
int a[SIZE] = {0}, prime[SIZE] = {0}, count = 0;
void init()
{
    int i = 2;
    while (i < SIZE)
    {
        prime[count++] = i;
        for (int j = 2 * i; j < SIZE; j += i)
            a[j] = 1;
        while (a[++i])
            ;
    }
}
int main(void)
{
#ifndef ONLINE_JUDGE
    ifstream fin("input.txt");
    cin.rdbuf(fin.rdbuf());
#endif
    init();
    int n;
    while (~scanf("%d",&n))
        for (int i = 0; prime[i] && prime[i] <= n; i++)
            printf("%d\n",prime[i]);

#ifndef ONLINE_JUDGE
    fin.close();
#endif
    return 0;
}