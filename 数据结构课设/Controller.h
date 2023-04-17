#include <iostream>
#include <windows.h>
#include "Data.h"
#include <stdlib.h>

class Controller
{
private:
    /* data */
    Data *data = Data::getInstance();
    //深搜算法，求所有路径
    void dfs(int *res, bool *vis, int num, int a, const int b);

public:
    Controller(/* args */);
    ~Controller();
    void menu();
    void add_station();
    void add_line();
    void delete_line();
    void lookup_beeline();
    void lookup_all_way();
    void lookup_graph();
};

Controller::Controller(/* args */)
{
}

Controller::~Controller()
{
}
void Controller::dfs(int *res, bool *vis, int num, int a, const int b)
{
    if (a == b)
    {
        std::cout << res[0];
        for (int i = 1; i < num; i++)
            std::cout << "->" << res[i];
        std::cout << std::endl;
        return;
    }
    for (int i = 0; i < data->getMaxN(); i++)
    {
        if (!vis[i] && data->isLine(i, a))
        {
            res[num] = i;
            vis[i] = true;
            dfs(res, vis, num + 1, i, b);
            vis[i] = false;
        }
    }
}
void Controller::menu()
{
    system("cls");
    std::cout << "----------------------地铁路线查询系统----------------------------" << std::endl;
    std::cout << "----------------------1.添加新站点-------------------------------" << std::endl;
    std::cout << "----------------------2.添加新路线-------------------------------" << std::endl;
    std::cout << "----------------------3.删除地铁路线-----------------------------" << std::endl;
    std::cout << "----------------------4.查询两个站点间的最短距离------------------" << std::endl;
    std::cout << "----------------------5.查询两个站点间的所有路径------------------" << std::endl;
    std::cout << "----------------------6.打印地铁网阵-----------------------------" << std::endl;
    std::cout << "----------------------7.退出------------------------------------" << std::endl;
    char ch;
    cin >> ch;
    getchar();
    while (!(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7'))
    {
        std::cout << "请输入正确的选择：" << std::endl;
        cin >> ch;
        getchar();
    }
    switch (ch)
    {
    case '1':
        add_station();
        break;
    case '2':
        add_line();
        break;
    case '3':
        delete_line();
        break;
    case '4':
        lookup_beeline();
        break;
    case '5':
        lookup_all_way();
        break;
    case '6':
        lookup_graph();
        break;
    case '7':
        data->save();
        exit(0);
        break;
    }
}
void Controller::add_station()
{
    //
    int a, dis;
    while (true)
    {
        system("cls");
        //
        int newStation = data->getAvailableStation();
        if (newStation == -1)
        {
            cout << "站点以全部使用" << endl;
            Sleep(2000);
            return;
        }
        std::cout << "你正在添加编号为" << newStation << "的地铁站口，" << std::endl;
        std::cout << "请从下列地铁站口选择一个，来连接编号为" << newStation << "的地铁站口（输入-1结束）：" << std::endl;
        data->printUsed();
        //
        std::cin >> a;
        if (a == -1)
            break;
        while (!data->isUsed(a))
        {
            std::cout << "编号输入错误，请重新输入：" << std::endl;
            std::cout << "你正在添加编号为" << newStation << "的地铁站口，" << std::endl;
            std::cout << "请从下列地铁站口选择一个，来连接编号为" << newStation << "的地铁站口（输入-1结束）：" << std::endl;
            data->printUsed();
            std::cin >> a;
        }
        std::cout << "请输入站口" << a << "和站口" << newStation << "之间的距离：";
        std::cin >> dis;
        //添加一个新站点 newStation
        data->insertLine(a, newStation, dis);
        cout << "新增线路：" << a << "站口到" << newStation << "站口，长度：" << data->getDistance(a, newStation) << endl;
        Sleep(1000);
    }
    std::cout << "路线更新成功" << std::endl;
    menu();
    Sleep(2000);
}
void Controller::delete_line()
{
    system("cls");
    std::cout << "请从下面选择被删除路线的两个站口序号：" << std::endl;
    data->printUsed();
    int a, b;
    std::cin >> a >> b;
    while (!data->isLine(a, b))
    {
        std::cout << "没有该路线，请重新输入：" << std::endl;
        std::cout << "请从下面选择被删除路线的两个站口序号：" << std::endl;
        data->printUsed();
        std::cin >> a >> b;
    }
    //删除路线
    data->deleteLine(a, b);
    std::cout << "路线删除成功" << std::endl;
    Sleep(2000);
    menu();
}
void Controller::lookup_beeline()
{
    system("cls");
    std::cout << "请从下面选择你要查询路线的起点和终点：" << std::endl;
    data->printUsed();
    int a, b;
    std::cin >> a >> b;
    getchar();
    if (!data->isLine(a, b))
    {
        std::cout << "没有该路线" << endl;
        Sleep(1000);
        menu();
        return;
    }
    std::cout << "地铁口" << a << "和地铁口" << b << "的最短距离是" << data->getDistance(a, b) << std::endl;
    std::cout << "输入回车键返回";
    getchar();
    menu();
}
void Controller::lookup_all_way()
{
    system("cls");
    std::cout << "请从下面选择你要查询路线的起点和终点：" << std::endl;
    data->printUsed();
    int a, b;
    std::cin >> a >> b;
    getchar();
    while (!data->isLine(a, b))
    {
        std::cout << "不存在该路线，请重新输入：" << std::endl;
        std::cout << "请从下面选择你要查询路线的起点和终点：" << std::endl;
        data->printUsed();
        std::cin >> a >> b;
        getchar();
    }
    int res[data->getMaxN()] = {a};
    bool vis[data->getMaxN()] = {false};
    vis[a] = true;
    std::cout << "站" << a << "和站" << b << "之前所有的路线：" << endl;
    dfs(res, vis, 1, a, b);
    std::cout << "输入回车建返回";
    getchar();
    menu();
}
void Controller::add_line()
{
    system("cls");
    std::cout << "请从下面选择你要添加路线的两个站点，以及两个站点之间的距离：" << std::endl;
    data->printUsed();
    int a, b, dis;
    std::cin >> a >> b >> dis;
    getchar();
    while (!(data->isUsed(a) && data->isUsed(b)))
    {
        std::cout << "输入错误" << std::endl;
        std::cout << "请从下面选择你要添加路线的两个站点，以及两个站点之间的距离：" << std::endl;
        data->printUsed();
        std::cin >> a >> b >> dis;
        getchar();
    }
    //添加一条新路线
    if (data->isLine(a, b))
    {
        std::cout << "站点" << a << "和站点" << b << "之间已经有一条长度为" << data->getDistance(a, b) << "的路线了，是否更新(Y/N)？" << std::endl;
        char ch;
        std::cin >> ch;
        getchar();
        if (!(ch == 'Y' || ch == 'y'))
            return;
    }
    data->insertLine(a, b, dis);
    cout << "新增线路：" << a << "站口到" << b << "站口，长度：" << data->getDistance(a, b) << endl;
    menu();
}
void Controller::lookup_graph()
{
    system("cls");
    cout<<"地铁路线总览"<<endl;
    data->printGraph();
    cout<<"按回车返回"<<endl;
    while(getchar()!='\n');
    menu();
}