#include<iostream>
using namespace std;
const int maxn = 10;
int n, k, ans;
void fun(char m[][maxn], int N, int K)
{
    if (K == k) //棋子都放完了
    {
        ans++;
        return;
    }
    if (N == n + 1)
        return;
    for (int j = 1; j <= n; j++) //遍历第N行
    {
        if (m[N][j] == '#') //是棋盘区
        {
            int i;
            for (i = 1; i < N; i++) //遍历列，我们一行只放一个棋子
                if (m[N - i][j] == 'o')//判断第j列有没有棋子
                    break; 
            if (i == N)    //m[N][j]的地方能放棋子
            {
                m[N][j] = 'o';        //放棋子
                fun(m, N + 1, K + 1); //进入下一行
                m[N][j] = '#';        //回溯，把棋子取回
            }
        }
    }
    fun(m, N + 1, K);//不放棋子，进入下一行
}
int main(void)
{
    while (cin >> n >> k)
    {
        if (n <= -1 && k <= -1)
            break;
        //
        char m[maxn][maxn] = {0};
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> m[i][j];
        //
        ans = 0;
        fun(m, 1, 0);
        cout << ans << endl;
    }
    return 0;
}