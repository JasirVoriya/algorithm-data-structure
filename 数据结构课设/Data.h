#include <fstream>
#include "Tools.h"
#include <stdlib.h>
#include <cstdio>
using namespace std;
class Data
{
private:
    Data();
    ~Data();
    const static int MAX_N = 50;
    const static int INF = 0x3f3f3f3f;
    int cnt;
    int Graph[MAX_N][MAX_N];
    int MinDis[MAX_N][MAX_N];
    bool used[MAX_N];

public:
    static Data *instance;
    static Data *getInstance();

    void save();
    void printUsed();
    void printGraph();
    void insertLine(int, int, int);
    void deleteLine(int, int);
    bool isLine(int, int);
    int getAvailableStation();
    bool isUsed(int);
    int getDistance(int, int);
    void updateMinDis();
    int getMaxN();
    int getMaxUesdCode();
};
Data *Data::instance = nullptr;
Data *Data::getInstance()
{
    if (!Data::instance)
        Data::instance = new Data();
    return instance;
}
Data::Data()
{
    ifstream file;
    file.open("data", ios::in);
    if (file.is_open())
    {
        cout << "从文件中加载数据" << endl;
        //加载地铁站数量
        file >> cnt;
        //加载已使用的地铁站
        for (int i = 0; i < MAX_N; i++)
            file >> used[i];
        //加载邻接矩阵
        for (int i = 0; i < MAX_N; i++)
            for (int j = 0; j < MAX_N; j++)
                file >> Graph[i][j];
        //弗洛伊德最短路算法，计算多源最短路
        memcpy(MinDis, Graph, sizeof(Graph));
        Tools::floyd(MinDis, MAX_N);
        file.close();
    }
    else
    {
        cout << "未找到数据文件，初始化数据" << endl;
        MinDis[0][0] = Graph[0][0] = 0;
        memset(used, false, sizeof(used));
        cnt = 0;
        used[cnt++] = true;
        for (int i = 0; i < MAX_N; i++)
            for (int j = 0; j < MAX_N; j++)
                MinDis[i][j] = Graph[i][j] = INF;
    }
    cout << "数据加载完成,当前站口数量：" << cnt << endl;
    Sleep(2000);
}
Data::~Data()
{
    save();
}
void Data::save()
{
    ofstream file;
    file.open("data", ios::out);
    file << cnt << endl;
    for (int i = 0; i < MAX_N; i++)
        file << used[i] << endl;
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            file << Graph[i][j] << endl;
    file.close();
}
void Data::printUsed()
{
    for (int i = 0; i < MAX_N; i++)
        if (used[i])
            cout << i << " ";
    cout << endl;
}
void Data::insertLine(int a, int b, int dis)
{
    Graph[a][b] = Graph[b][a] = dis;
    Graph[a][a] = Graph[b][b] = 0;

    //如果在插入之前a站没有使用
    if (!used[a])
    {
        used[a] = true;
        cnt++;
    }
    if (!used[b])
    {
        used[b] = true;
        cnt++;
    }
    //弗洛伊德最短路算法，计算多源最短路
    updateMinDis();
}
void Data::deleteLine(int a, int b)
{
    Graph[a][b] = Graph[b][a] = INF;
    Graph[a][a] = Graph[b][b] = INF;
    //
    bool available = true;
    for (int i = 0; i < MAX_N; i++)
    {
        //如果a站有线路，那么a站就不可用
        if (Graph[a][i] < INF)
            available = false;
    }
    //如果删除之后a站可用，那么就要将a站标记为可用（即标记为未使用）
    if (available)
    {

        used[a] = false;
        cnt--;
    }
    //
    available = true;
    for (int i = 0; i < MAX_N; i++)
    {
        if (Graph[b][i] < INF)
            available = false;
    }
    if (available)
    {
        used[b] = false;
        cnt--;
    }
    //弗洛伊德最短路算法，计算多源最短路
    updateMinDis();
}
bool Data::isLine(int a, int b)
{
    if (a >= 0 && a < MAX_N && b >= 0 && b < MAX_N)
        return MinDis[a][b] < INF;
    return false;
}
int Data::getAvailableStation()
{
    for (int i = 0; i < MAX_N; i++)
        if (!used[i])
            return i;
    return -1;
}
bool Data::isUsed(int a)
{
    return used[a];
}
int Data::getDistance(int a, int b)
{
    return MinDis[a][b];
}
void Data::updateMinDis()
{
    memcpy(MinDis, Graph, sizeof(Graph));
    Tools::floyd(MinDis, MAX_N);
}
int Data::getMaxN()
{
    return Data::MAX_N;
}
int Data::getMaxUesdCode()
{
    int ans = 0;
    for (int i = 0; i < MAX_N; i++)
        if (used[i])
            ans = i;
    return ans;
}
void Data::printGraph()
{
    int n = getMaxUesdCode();
    //
    printf("    ");
    for (int i = 0; i <= n; i++)
        printf("%3d", i);
    puts("");
    //
    printf("    ");
    for (int i = 0; i <= n; i++)
        printf("___");
    puts("");
    //
    for (int i = 0; i <= n; i++)
    {
        printf("%-3d|", i);
        for (int j = 0; j <= n; j++)
        {
            if(Graph[i][j]!=INF)
            printf("%3d", Graph[i][j]);
            else printf("%3d", -1);

        }
        puts("");
    }
}