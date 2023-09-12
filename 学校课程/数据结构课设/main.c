#include <stdbool.h>
#include <stdio.h>
#include <windows.h>

#define MAX_N 50
#define INF 0x3f3f3f3f

/**
 * ############################## 数据结构 ##############################
 * cnt: 地铁站数量
 * Graph: 邻接矩阵
 * MinDis: 多源最短路
 * used: 地铁站是否使用
 * ############################## 数据结构 ##############################
 */
typedef struct {
    int cnt;
    int Graph[MAX_N][MAX_N];
    int MinDis[MAX_N][MAX_N];
    bool used[MAX_N];
} Data;
/**
 * ############################## 函数声明 ##############################
 * floyd: 弗洛伊德最短路算法，计算多源最短路
 * loadData: 加载数据
 * save: 保存数据
 * printUsed: 打印已使用的地铁站
 * getMaxUesdCode: 获取最大的地铁站编号
 * printGraph: 打印地铁网阵
 * updateMinDis: 更新多源最短路
 * insertLine: 插入一条新路线
 * deleteLine: 删除一条路线
 * isLine: 判断两个地铁站之间是否有路线
 * getAvailableStation: 获取一个未使用的地铁站
 * isUsed: 判断一个地铁站是否被使用
 * getDistance: 获取两个地铁站之间的距离
 * ############################## 函数声明 ##############################
 */
void floyd(Data *data) {
    for (int k = 0; k < MAX_N; k++)
        for (int i = 0; i < MAX_N; i++)
            for (int j = 0; j < MAX_N; j++)
                data->MinDis[i][j] =
                    min(data->MinDis[i][j],
                        data->MinDis[i][k] + data->MinDis[k][j]);
}
Data *loadData() {
    FILE *file = fopen("data", "r");
    Data *data = (Data *)malloc(sizeof(Data));
    if (file != NULL) {
        printf("从文件中加载数据\n");
        // 加载地铁站数量
        fscanf(file, "%d\n", &data->cnt);
        printf("当前站口数量：%d\n", data->cnt);
        // 加载已使用的地铁站
        printf("加载已使用的地铁站\n");
        for (int i = 0; i < MAX_N; i++) {
            fscanf(file, "%d\n", &data->used[i]);
            printf("%d ", data->used[i]);
        }
        printf("\n加载邻接矩阵\n");
        // 加载邻接矩阵
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                fscanf(file, "%d\n", &data->Graph[i][j]);
                printf("%d ", data->Graph[i][j]);
            }
            printf("\n");
        }
        // 弗洛伊德最短路算法，计算多源最短路
        memcpy(data->MinDis, data->Graph, sizeof(data->Graph));
        floyd(data);
        printf("计算多源最短路完成\n");
        // fclose(file);
        printf("文件已关闭\n");
    } else {
        printf("未找到数据文件，初始化数据\n");
        data->MinDis[0][0] = data->Graph[0][0] = 0;
        memset(data->used, false, sizeof(data->used));
        data->cnt = 0;
        data->used[data->cnt++] = true;
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                data->MinDis[i][j] = data->Graph[i][j] = INF;
            }
        }
    }
    printf("数据加载成功\n");
    Sleep(2000);
    return data;
}
void save(Data *data) {
    FILE *file = fopen("data", "w");
    if (file != NULL) {
        fprintf(file, "%d\n", data->cnt);
        for (int i = 0; i < MAX_N; i++) {
            fprintf(file, "%d\n", data->used[i]);
        }
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                fprintf(file, "%d\n", data->Graph[i][j]);
            }
        }
        fclose(file);
        printf("数据保存成功\n");
    }
}
void printUsed(Data *data) {
    for (int i = 0; i < MAX_N; i++) {
        if (data->used[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int getMaxUesdCode(Data *data) {
    int ans = 0;
    for (int i = 0; i < MAX_N; i++)
        if (data->used[i]) ans = i;
    return ans;
}
void printGraph(Data *data) {
    int n = getMaxUesdCode(data);
    //
    printf("    ");
    for (int i = 0; i <= n; i++) printf("%3d", i);
    puts("");
    //
    printf("    ");
    for (int i = 0; i <= n; i++) printf("___");
    puts("");
    //
    for (int i = 0; i <= n; i++) {
        printf("%-3d|", i);
        for (int j = 0; j <= n; j++) {
            if (data->Graph[i][j] != INF)
                printf("%3d", data->Graph[i][j]);
            else
                printf("%3d", -1);
        }
        puts("");
    }
}
void updateMinDis(Data *data) {
    memcpy(data->MinDis, data->Graph, sizeof(data->Graph));
    floyd(data);
}
void insertLine(Data *data, int a, int b, int dis) {
    data->Graph[a][b] = data->Graph[b][a] = dis;
    data->Graph[a][a] = data->Graph[b][b] = 0;

    // 如果在插入之前a站没有使用
    if (!data->used[a]) {
        data->used[a] = true;
        data->cnt++;
    }
    if (!data->used[b]) {
        data->used[b] = true;
        data->cnt++;
    }
    // 弗洛伊德最短路算法，计算多源最短路
    updateMinDis(data);
}
void deleteLine(Data *data, int a, int b) {
    data->Graph[a][b] = data->Graph[b][a] = INF;
    data->Graph[a][a] = data->Graph[b][b] = INF;
    //
    bool available = true;
    for (int i = 0; i < MAX_N; i++) {
        // 如果a站有线路，那么a站就不可用
        if (data->Graph[a][i] < INF) available = false;
    }
    // 如果删除之后a站可用，那么就要将a站标记为可用（即标记为未使用）
    if (available) {
        data->used[a] = false;
        data->cnt--;
    }
    //
    available = true;
    for (int i = 0; i < MAX_N; i++) {
        if (data->Graph[b][i] < INF) available = false;
    }
    if (available) {
        data->used[b] = false;
        data->cnt--;
    }
    // 弗洛伊德最短路算法，计算多源最短路
    updateMinDis(data);
}
bool isConnected(Data *data, int a, int b) {
    if (a >= 0 && a < MAX_N && b >= 0 && b < MAX_N)
        return data->MinDis[a][b] < INF;
    return false;
}
bool isLine(Data *data, int a, int b) {
    if (a >= 0 && a < MAX_N && b >= 0 && b < MAX_N)
        return data->Graph[a][b] < INF;
    return false;
}
int getAvailableStation(Data *data) {
    for (int i = 0; i < MAX_N; i++)
        if (!data->used[i]) return i;
    return -1;
}
bool isUsed(Data *data, int a) { return data->used[a]; }
int getDistance(Data *data, int a, int b) { return data->MinDis[a][b]; }

/**
 * ############################## 全局变量 ##############################
 * data: 数据
 * ############################## 全局变量 ##############################
 */
Data *data = NULL;

/**
 * ############################## 函数声明 ##############################
 * menu: 菜单
 * add_station: 添加新站点
 * delete_line: 删除地铁路线
 * lookup_beeline: 查询两个站点间的最短距离
 * lookup_all_way: 查询两个站点间的所有路径
 * add_line: 添加新路线
 * lookup_graph: 打印地铁网阵
 * dfs: 深搜算法，求所有路径
 * ############################## 函数声明 ##############################
 */
void menu(Data *data);
void dfs(Data *data, int *res, bool *vis, int num, int a, const int b,
         int dis) {
    if (a == b) {
        printf("%d", res[0]);
        for (int i = 1; i < num; i++) {
            printf("->%d", res[i]);
        }
        printf("(距离：%d)\n", dis);
        return;
    }
    for (int i = 0; i < MAX_N; i++) {
        if (!vis[i] && isLine(data, i, a)) {
            res[num] = i;
            vis[i] = true;
            dfs(data, res, vis, num + 1, i, b, dis + data->Graph[i][a]);
            vis[i] = false;
        }
    }
}
void add_station(Data *data) {
    //
    int a, dis;
    while (true) {
        system("cls");
        //
        int newStation = getAvailableStation(data);
        if (newStation == -1) {
            printf("站点以全部使用\n");
            Sleep(2000);
            return;
        }
        printf("你正在添加编号为%d的地铁站口，\n", newStation);
        printf(
            "请从下列地铁站口选择一个，来连接编号为%d的地铁站口（输入-"
            "1结束）：\n",
            newStation);
        printUsed(data);
        scanf("%d", &a),getchar();
        if (a == -1) break;
        while (!isUsed(data, a)) {
            printf("编号输入错误，请重新输入：\n");
            printf("你正在添加编号为%d的地铁站口，\n", newStation);
            printf(
                "请从下列地铁站口选择一个，来连接编号为%d的地铁站口（输入-"
                "1结束）：\n",
                newStation);
            printUsed(data);
            scanf("%d", &a),getchar();
        }
        printf("请输入站口%d和站口%d之间的距离：", a, newStation);
        scanf("%d", &dis),getchar();
        // 添加一个新站点 newStation
        insertLine(data, a, newStation, dis);
        printf("新增线路：%d站口到%d站口，长度：%d\n", a, newStation,
               getDistance(data, a, newStation));
        Sleep(1000);
    }
    printf("路线更新成功\n");
    menu(data);
    Sleep(2000);
}
void delete_line(Data *data) {
    system("cls");
    printf("请从下面选择被删除路线的两个站口序号：\n");
    printUsed(data);
    int a, b;
    scanf("%d %d", &a, &b),getchar();
    while (!isLine(data, a, b)) {
        printf("没有该路线，请重新输入：\n");
        printf("请从下面选择被删除路线的两个站口序号：\n");
        printUsed(data);
        scanf("%d %d", &a, &b),getchar();
    }
    deleteLine(data, a, b);
    printf("路线删除成功\n");
    Sleep(2000);
    menu(data);
}

void lookup_beeline(Data *data) {
    system("cls");
    printf("请从下面选择你要查询路线的起点和终点：\n");
    printUsed(data);
    int a, b;
    scanf("%d %d", &a, &b),getchar();
    if (!isConnected(data, a, b)) {
        printf("没有该路线\n");
        Sleep(1000);
        menu(data);
        return;
    }
    printf("地铁口%d和地铁口%d的最短距离是%d\n", a, b, getDistance(data, a, b));
    printf("输入回车键返回");
    getchar();
    menu(data);
}

void lookup_all_way(Data *data) {
    system("cls");
    printf("请从下面选择你要查询路线的起点和终点：\n");
    printUsed(data);
    int a, b;
    scanf("%d %d", &a, &b),getchar();
    while (!isConnected(data, a, b)) {
        printf("不存在该路线，请重新输入：\n");
        printf("请从下面选择你要查询路线的起点和终点：\n");
        printUsed(data);
        scanf("%d %d", &a, &b),getchar();
    }
    int res[MAX_N] = {a};
    bool vis[MAX_N] = {false};
    vis[a] = true;
    printf("站%d和站%d之前所有的路线：\n", a, b);
    dfs(data, res, vis, 1, a, b, 0);
    printf("输入回车键返回");
    getchar();
    menu(data);
}
void add_line(Data *data) {
    system("cls");
    printf("请从下面选择你要添加路线的两个站点，以及两个站点之间的距离：\n");
    printUsed(data);
    int a, b, dis;
    scanf("%d %d %d", &a, &b, &dis),getchar();
    while (!(isUsed(data, a) && isUsed(data, b))) {
        printf("输入错误\n");
        printf(
            "请从下面选择你要添加路线的两个站点，以及两个站点之间的距离：\n");
        printUsed(data);
        scanf("%d %d %d", &a, &b, &dis),getchar();
    }
    if (isLine(data, a, b)) {
        printf(
            "站点%d和站点%d之间已经有一条长度为%d的路线了，是否更新(Y/N)？\n",
            a, b, getDistance(data, a, b));
        char ch;
        scanf("%c", &ch),getchar();
        if (!(ch == 'Y' || ch == 'y')) return;
    }
    insertLine(data, a, b, dis);
    printf("新增线路：%d站口到%d站口，长度：%d\n", a, b,
           getDistance(data, a, b));
    menu(data);
}

void lookup_graph(Data *data) {
    system("cls");
    printf("地铁路线总览\n");
    printGraph(data);
    printf("按回车返回\n");
    while (getchar() != '\n')
        ;
    menu(data);
}
void menu(Data *data) {
    system("cls");
    printf("----------------------地铁路线查询系统--------------------\n");
    printf("----------------------1.添加新站点-----------------------\n");
    printf("----------------------2.添加新路线-----------------------\n");
    printf("----------------------3.删除地铁路线---------------------\n");
    printf("----------------------4.查询两个站点间的最短距离----------\n");
    printf("----------------------5.查询两个站点间的所有路径----------\n");
    printf("----------------------6.打印地铁网阵---------------------\n");
    printf("----------------------7.退出并保存-----------------------\n");
    char ch;
    scanf("%c", &ch),getchar();
    while (!(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' ||
             ch == '6' || ch == '7')) {
        printf("请输入正确的选择：\n");
        scanf("%c", &ch),getchar();
    }
    switch (ch) {
        case '1':
            add_station(data);
            break;
        case '2':
            add_line(data);
            break;
        case '3':
            delete_line(data);
            break;
        case '4':
            lookup_beeline(data);
            break;
        case '5':
            lookup_all_way(data);
            break;
        case '6':
            lookup_graph(data);
            break;
        case '7':
            save(data);
            exit(0);
            break;
    }
}

int main(void) {
    system("chcp 65001");
    menu(loadData());
    return 0;
}