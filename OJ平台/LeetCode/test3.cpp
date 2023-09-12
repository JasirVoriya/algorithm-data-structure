#include <iostream>
using namespace std;
typedef struct que {
    int x; //横坐标
    int y; //纵坐标
    int s; //当前所走步数
} kk;
kk test[2501]; //最多会有2500种可能
int book[51][51]; //地图是50*50的
int move1[4][2] = {
    { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } //定义上下左右四种移动方式
};
char map[51][51]; //定义地图模型
int main()
{
    int head, tail;
    int i, j, n, m;
    int startx, starty, tx, ty;
    int flag, p, q;
    cout << "Please input map size:";
    cin >> m >> n; //初始化地图大小m*n模型的地图
    getchar();
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%c", &map[i][j]); //.表示可通过  *表示障碍物不可通过
            getchar();
        }
    }
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << "Pleaase input start and hostage cox" << endl;
    cin >> startx >> starty;
    cin >> tx >> ty;
    head = tail = 1; //初始化队列
    book[startx][starty] = 1;
    test[tail].x = startx; //初始化起点坐标
    test[tail].y = starty; //初始化起点坐标
    test[tail].s = 0; //初始化时步数为0
    tail++; //开始当前节点的广搜
    flag = 0; //表示当前还未找到人质
    while (head < tail) //开始寻找人质
    {
        for (int k = 0; k < 4; k++) {
            p = test[head].x + move1[k][0]; //做出尝试
            q = test[head].y + move1[k][1];
            if (p < 1 || p > m || q < 1 || q > n || map[p][q] == '*')
                continue; //如果已经越界，则进行另一个方向的尝试
            if (book[p][q] == 0) //如果这个点没有被搜过的话就可以进行搜索，否则重复搜索浪费时间
            {
                cout << p << " " << q << endl;
                getchar();
                book[p][q] == 1; //把搜过的点做上标记
                test[tail].x = p; //把新的节点加入队列进行遍历
                test[tail].y = q;
                test[tail].s += test[head].s + 1; //路径加上1
                tail++;
            }
            if (p == tx && q == ty) {
                flag = 1;
                break; //说明本次已经找到人质
            }
        }
        if (flag)
            break; //如果已经找到人质则可以推出了
        head++; //否则就用另一个点开始广度搜索
    }
    cout << "This time search spend:";
    cout << test[tail - 1].s << endl; //tail为下一个元素，故需要-1
    return 0;
}
