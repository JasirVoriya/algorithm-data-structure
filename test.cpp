#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATIONS 100
#define INF 9999

typedef struct {
    char name[50];  // 地铁口名称
} Station;

typedef struct {
    int distance;  // 距离
    int prev;      // 前一个地铁口的索引
} PathInfo;

typedef struct {
    Station stations[MAX_STATIONS];  // 地铁口数组
    int adjacencyMatrix[MAX_STATIONS]
                       [MAX_STATIONS];  // 邻接矩阵表示地铁线路连接关系
    int numStations;                    // 地铁口数量
} SubwaySystem;

void initSubwaySystem(SubwaySystem* subway) {
    subway->numStations = 0;  // 初始化地铁口数量为0
    int i, j;
    for (i = 0; i < MAX_STATIONS; i++) {
        for (j = 0; j < MAX_STATIONS; j++) {
            if (i == j)
                subway->adjacencyMatrix[i][j] =
                    0;  // 对角线上的距离为0，表示同一个地铁口
            else
                subway->adjacencyMatrix[i][j] =
                    INF;  // 其他位置的距离初始化为无穷大，表示不直接相连
        }
    }
}

int addStation(SubwaySystem* subway, const char* name) {
    if (subway->numStations >= MAX_STATIONS) {
        printf("已达到最大站点数量。\n");
        return 0;
    }

    strcpy(subway->stations[subway->numStations].name,
           name);           // 将地铁口名称复制到地铁口数组中
    subway->numStations++;  // 地铁口数量加1

    return 1;
}

int findStationIndex(SubwaySystem* subway, const char* name) {
    int i;
    for (i = 0; i < subway->numStations; i++) {
        if (strcmp(subway->stations[i].name, name) ==
            0) {       // 比较地铁口名称是否匹配
            return i;  // 返回地铁口在数组中的索引
        }
    }
    return -1;  // 没有找到匹配的地铁口，返回-1
}

void addConnection(SubwaySystem* subway, const char* station1,
                   const char* station2, int distance) {
    int index1 = findStationIndex(subway, station1);  // 查找起点站的索引
    int index2 = findStationIndex(subway, station2);  // 查找终点站的索引

    if (index1 == -1 || index2 == -1) {
        printf("一个或两个站点不存在。\n");
        return;
    }

    subway->adjacencyMatrix[index1][index2] =
        distance;  // 在邻接矩阵中记录两个地铁口的距离
    subway->adjacencyMatrix[index2][index1] =
        distance;  // 由于是无向图，也要记录反向的距离
}

void printStationInfo(SubwaySystem* subway, const char* name) {
    int index = findStationIndex(subway, name);  // 查找地铁口的索引

    if (index == -1) {
        printf("未找到站点。\n");
        return;
    }

    printf("地铁口名称: %s\n", subway->stations[index].name);
    printf("所属线路: ");
    int i;
    for (i = 0; i < subway->numStations; i++) {
        if (subway->adjacencyMatrix[index][i] !=
            INF) {  // 遍历邻接矩阵，找到相连的地铁口
            printf("%s ", subway->stations[i].name);
        }
    }
    printf("\n");
}

void dijkstra(SubwaySystem* subway, int start, int end) {
    int visited[MAX_STATIONS] = {0};  // 记录地铁口是否被访问过
    PathInfo paths[MAX_STATIONS];     // 记录最短路径信息
    int i, j;

    for (i = 0; i < subway->numStations; i++) {
        paths[i].distance = INF;  // 初始化路径距离为无穷大
        paths[i].prev = -1;       // 初始化前一个地铁口的索引为-1
    }

    paths[start].distance = 0;  // 起始地铁口到自身的距离为0

    for (i = 0; i < subway->numStations - 1; i++) {
        int minDistance = INF;
        int current = -1;

        for (j = 0; j < subway->numStations; j++) {
            if (!visited[j] && paths[j].distance < minDistance) {
                minDistance = paths[j].distance;
                current = j;  // 找到未访问过且距离最小的地铁口
            }
        }

        if (current == -1) {
            break;
        }

        visited[current] = 1;  // 标记当前地铁口为已访问

        for (j = 0; j < subway->numStations; j++) {
            if (!visited[j] && subway->adjacencyMatrix[current][j] != INF) {
                int distance = paths[current].distance +
                               subway->adjacencyMatrix[current][j];
                if (distance <
                    paths[j].distance) {  // 更新路径距离和前一个地铁口的索引
                    paths[j].distance = distance;
                    paths[j].prev = current;
                }
            }
        }
    }

    if (paths[end].prev == -1) {
        printf("无法找到两个站点之间的路径。\n");
        return;
    }

    printf("从%s到%s的最短路径：\n", subway->stations[start].name,
           subway->stations[end].name);

    int pathStack[MAX_STATIONS];
    int stackIndex = 0;
    int current = end;

    while (current != start) {
        pathStack[stackIndex++] = current;  // 将路径上的地铁口索引入栈
        current = paths[current].prev;      // 回溯到前一个地铁口
    }

    pathStack[stackIndex++] = start;  // 将起点站的索引入栈

    while (stackIndex > 0) {
        printf("%s", subway->stations[pathStack[--stackIndex]]
                         .name);  // 出栈并打印地铁口名称
        if (stackIndex > 0) {
            printf(" -> ");
        }
    }
    printf("\n");
}

void findAllPathsHelper(SubwaySystem* subway, int start, int end, int* visited,
                        int* path, int pathIndex) {
    visited[start] = 1;         // 标记当前地铁口为已访问
    path[pathIndex++] = start;  // 将当前地铁口索引加入路径中

    if (start == end) {  // 如果找到目标地铁口，打印路径
        int i;
        for (i = 0; i < pathIndex; i++) {
            printf("%s", subway->stations[path[i]].name);
            if (i < pathIndex - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        int i;
        for (i = 0; i < subway->numStations; i++) {
            if (!visited[i] && subway->adjacencyMatrix[start][i] != INF) {
                findAllPathsHelper(subway, i, end, visited, path,
                                   pathIndex);  // 递归搜索下一个地铁口
            }
        }
    }

    visited[start] = 0;  // 清除标记，以便在不同路径之间进行回溯
    pathIndex--;
}

void findAllPaths(SubwaySystem* subway, int start, int end) {
    int visited[MAX_STATIONS] = {0};  // 记录地铁口是否被访问过
    int path[MAX_STATIONS];           // 记录路径
    int pathIndex = 0;

    findAllPathsHelper(subway, start, end, visited, path, pathIndex);
}

void printMenu() {
    printf("系统菜单 ===\n");
    printf("1. 创建地铁线路\n");
    printf("2. 修改地铁线路\n");
    printf("3. 删除地铁线路\n");
    printf("4. 查询站点信息\n");
    printf("5. 查找最短路径\n");
    printf("6. 查找所有路径\n");
    printf("7. 退出\n");
    printf("====================\n");
    printf("请输入您的选择: ");
}

int main() {
    SubwaySystem subway;
    initSubwaySystem(&subway);

    int choice;
    char station1[50], station2[50];
    int distance, index, start, end;

    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar();  // 消耗换行符

        switch (choice) {
            case 1:
                printf("请输入新站点的名称: ");
                fgets(station1, sizeof(station1), stdin);
                station1[strcspn(station1, "\n")] = '\0';  // 去除末尾的换行符

                if (addStation(&subway, station1)) {
                    printf("站点添加成功。\n");
                }
                break;

            case 2:
                printf("请输入要修改的站点名称: ");
                fgets(station1, sizeof(station1), stdin);
                station1[strcspn(station1, "\n")] = '\0';  // 去除末尾的换行符

                index = findStationIndex(&subway, station1);

                if (index == -1) {
                    printf("未找到站点。\n");
                    break;
                }

                printf("请输入新的站点名称: ");
                fgets(station2, sizeof(station2), stdin);
                station2[strcspn(station2, "\n")] = '\0';  // 去除末尾的换行符

                strcpy(subway.stations[index].name, station2);
                printf("站点修改成功。\n");
                break;

            case 3:
                printf("请输入要删除的站点名称: ");
                fgets(station1, sizeof(station1), stdin);
                station1[strcspn(station1, "\n")] = '\0';  // 去除末尾的换行符

                index = findStationIndex(&subway, station1);

                if (index == -1) {
                    printf("未找到站点。\n");
                    break;
                }

                for (int i = 0; i < subway.numStations; i++) {
                    subway.adjacencyMatrix[index][i] =
                        INF;  // 删除与该站点相关的边
                }

                for (int i = index + 1; i < subway.numStations; i++) {
                    strcpy(subway.stations[i - 1].name,
                           subway.stations[i].name);  // 将后面的站点向前移动
                }

                subway.numStations--;  // 地铁口数量减1

                printf("站点删除成功。\n");
                break;

            case 4:
                printf("请输入要查询的站点名称: ");
                fgets(station1, sizeof(station1), stdin);
                station1[strcspn(station1, "\n")] = '\0';  // 去除末尾的换行符

                printStationInfo(&subway, station1);
                break;

            case 5:
                printf("请输入起始站点名称: ");
                fgets(station1, sizeof(station1), stdin);
                station1[strcspn(station1, "\n")] = '\0';  // 去除末尾的换行符

                printf("请输入目标站点名称: ");
                fgets(station2, sizeof(station2), stdin);
                station2[strcspn(station2, "\n")] = '\0';  // 去除末尾的换行符

                start = findStationIndex(&subway, station1);
                end = findStationIndex(&subway, station2);

                if (start == -1 || end == -1) {
                    printf("一个或两个站点不存在。\n");
                    break;
                }

                dijkstra(&subway, start, end);
                break;

            case 6:
                printf("请输入起始站点名称: ");
                fgets(station1, sizeof(station1), stdin);
                station1[strcspn(station1, "\n")] = '\0';  // 去除末尾的换行符

                printf("请输入目标站点名称: ");
                fgets(station2, sizeof(station2), stdin);
                station2[strcspn(station2, "\n")] = '\0';  // 去除末尾的换行符

                start = findStationIndex(&subway, station1);
                end = findStationIndex(&subway, station2);

                if (start == -1 || end == -1) {
                    printf("一个或两个站点不存在。\n");
                    break;
                }

                printf("%s和%s之间的所有路径：\n", subway.stations[start].name,
                       subway.stations[end].name);
                findAllPaths(&subway, start, end);
                break;

            case 7:
                printf("退出程序。\n");
                exit(0);
                break;

            default:
                printf("无效的选择。\n");
                break;
        }
    }

    return 0;
}
