#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<stack>
using namespace std;
#define N 15
#define M 25
struct zuobiao {
    int x;//横坐标
    int y;//纵坐标
};
stack<zuobiao>P1,P2;
int sum=0;//落子的数量
char chess[N][N];//棋盘
char player1='1',player2='2';//p1,p2玩家的棋子
void qipan();//打印棋盘
void Menu();//菜单
char choosemode();//选择模式
void start();//开始
int Rechess(char player);//悔棋
void ReGame();//在来一局
//玩家
void put1(int *x,int *y);//玩家1输入
void put2(int *x,int *y);//玩家2输入
//傻瓜电脑
void AI(int *x,int *y);
int mark(int x,int y);
int isGameOver(int x,int y);//判断游戏结束
void endGame();//游戏结束
void gotoxy(int i,int j) { //移动光标（不闪烁光标）
    COORD position= {i,j};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);//移动光标
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//隐藏光标
}
/*void gotoxyz(int i,int j) { //移动光标（闪烁光标）
    COORD position= {i,j};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);//移动光标
    CONSOLE_CURSOR_INFO cursor_info = {1, 1};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//显示光标
}*/
void initialion() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            chess[i][j]=' ';
        }
    }
    while(!P1.empty()) {
        P1.top();
        P1.pop();
    }
    while(!P2.empty()) {
        P2.top();
        P2.pop();
    }
}
int main() {
    start();
}
void start() {
    initialion();
    Menu();
    getch();
    system("cls");
    gotoxy(0,0);
    char T=choosemode();
    while(T!='n') {
        system("cls");
        gotoxy(0,0);
        initialion();
        T=choosemode();
    }
    system("cls");
    gotoxy(0,0);
    endGame();
}
void endGame() {
    printf("\t\t ************************\n");
    printf("\t\t *                      *\n");
    printf("\t\t *     感谢您的游玩!    *\n");
    printf("\t\t *                      *\n");
    printf("\t\t ************************\n");
}
void ReGame() {
    printf("\t\t ************************\n");
    printf("\t\t *                      *\n");
    printf("\t\t *     是否在来一局？   *\n");
    printf("\t\t *      y   or   n      *\n");
    printf("\t\t ************************\n");
}
void Menu() {
    printf("\t\t ************************\n");
    printf("\t\t *        五子棋        *\n");
    printf("\t\t *                      *\n");
    printf("\t\t *       开始游戏       *\n");
    printf("\t\t ************************\n");
    printf("\t\t      按任意键开始游戏   \n");
}
char choosemode() {
    int a1=N/2,a2=N/2,b1=N/2,b2=N/2;
    printf("\t\t ************************\n");
    printf("\t\t *      1.人人对战      *\n");
    printf("\t\t *                      *\n");
    printf("\t\t *      2.人机对战      *\n");
    printf("\t\t ************************\n");
    printf("\t\t 请选择模式！\n");
    int t;
    t=getch();
    while(t!='1'&&t!='2') {
        printf("输入错误,请重新输入:\n");
        t=getch();
    }
    system("mode con cols=100 lines=40");
    if(t=='1') {
        while(1) {
            /* 人人对战 */
            put1(&a1,&a2);//P1回合
            if(isGameOver(a1,a2)==1) {
                printf("玩家1胜利!!!\n");//对局结束
                break;
            }
            put2(&b1,&b2);//P2回合
            if(isGameOver(b1,b2)==1) {
                printf("玩家2胜利!!!\n");//对局结束
                break;
            }
            if(isGameOver(b1,b2)==2) {
                printf("平局!!!\n");//对局结束
                break;
            }
        }
    } else if(t=='2') {
        while(1) {
            /* 人机对战 */
            put1(&a1,&a2);//P1回合
            if(isGameOver(a1,a2)==1) {
                printf("玩家1胜利!!!\n");//对局结束
                break;
            }
            AI(&b1,&b2);//傻瓜电脑回合
            if(isGameOver(b1,b2)==1) {
                printf("傻瓜电脑胜利!!!\n");//对局结束
                break;
            }
            if(isGameOver(b1,b2)==2) {
                printf("平局!!!\n");//对局结束
                break;
            }
        }
    }
    ReGame();
    t=getch();
    while(t!='y'&&t!='n') {
        printf("输入错误！重新输入\n");
        t=getch();
    }
    return t;
}
void put1(int *x,int *y) {
    int a=*x,b=*y,ff=0;
    char T;
    zuobiao Ply1;//记录p1的棋子
    T=chess[a][b];
    chess[*x][*y]=player1;
    gotoxy(0,0);
    qipan();
    while(1) {
        gotoxy(100,0);
        printf("                                                      \n");
        int t;
        t=getch();
        // 72上  75左  80下  77右
        if(t==13) {
            if(T!=' ') {
                //gotoxy(100,20);
                printf("p1你不能下在这!");
                continue;
            } else {
                Ply1.x=*x;
                Ply1.y=*y;
                P1.push(Ply1);
                sum++;
                break;
            }
        } else if(t==224) {
            t=getch();
            switch(t) {  // 上 下 左 右控制方向 回车落子
            case 72:
                (*x)--;
                break;
            case 80:
                (*x)++;
                break;
            case 75:
                (*y)--;
                break;
            case 77:
                (*y)++;
                break;
            }
        } else if(t=='r') {
            chess[*x][*y]=' ';
            ff=Rechess(player2);
        }
        if(ff==1)
            break;
        if(*x<0)
            *x=N-1;
        if(*y<0)
            *y=N-1;
        if(*x>=N)
            *x=0;
        if(*y>=N)
            *y=0;
        chess[a][b]=T;
        a=*x;
        b=*y;
        T=chess[a][b];
        chess[*x][*y]=player1;
        gotoxy(0,0);
        qipan();
    }
}
void put2(int *x,int *y) {
    int a=*x,b=*y,ff=0;
    char T;
    zuobiao Ply2;
    T=chess[a][b];
    chess[*x][*y]=player2;
    gotoxy(0,0);
    qipan();
    while(1) {
        gotoxy(100,0);
        printf("                                                    ");
        int t,flag=0;
        t=getch();
        switch(t) {   // w,s,a,d控制方向   空格落子
        case 'w':
            (*x)--;
            break;
        case 's':
            (*x)++;
            break;
        case 'a':
            (*y)--;
            break;
        case 'd':
            (*y)++;
            break;
        case ' ':
            flag=1;
            break;
        case 'r': {
            chess[*x][*y]=' ';
            ff=Rechess(player1);
        }
        }
        if(ff==1)
            break;
        if(*x<0)
            *x=N-1;
        if(*y<0)
            *y=N-1;
        if(*x>=N)
            *x=0;
        if(*y>=N)
            *y=0;
        chess[a][b]=T;
        a=*x;
        b=*y;
        T=chess[*x][*y];
        chess[*x][*y]=player2;
        gotoxy(0,0);
        qipan();
        if(flag) {
            if(T!=' ') {
                //gotoxy(100,20);
                printf("p2你不能下在这!");
            } else {
                Ply2.x=*x;
                Ply2.y=*y;
                P2.push(Ply2);
                sum++;
                break;
            }
        }
    }
}
int Rechess(char player) {
   
    return 1;
}
void qipan() {
    char p[N][N][4];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(chess[i][j]==' ') {
                strcpy(p[i][j]," \0");
            }
            if(chess[i][j]==player1) {
                strcpy(p[i][j],"●\0");
            }
            if(chess[i][j]==player2) {
                strcpy(p[i][j],"◎\0");
            }
        }
    }
    printf("                                   五子棋                            \n");
    printf("                                                                     \n");
    printf("    p1 ↑上 ↓下 ←左 →右 回车落子          p2 w 上 s下 a左 d右 空格落子\n");
    printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");
    printf("       ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐\n");
    for(int i=0,j=0; i<N-1; i++,j++) {
        printf("     %2ld│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%d\n",j,p[i][0],p[i][1],p[i][2],p[i][3],p[i][4],p[i][5],p[i][6],p[i][7],p[i][8],p[i][9],p[i][10],p[i][11],p[i][12],p[i][13],p[i][14],j);
        printf("       ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤\n");
    }
    printf("     14│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%3s│%d\n",p[14][0],p[14][1],p[14][2],p[14][3],p[14][4],p[14][5],p[14][6],p[14][7],p[14][8],p[14][9],p[14][10],p[14][11],p[14][12],p[14][13],p[14][14],14);
    printf("       └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘\n");
    printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");
}
int isGameOver(int x,int y) {
    char T=chess[x][y];
    if(T==' ')
        return 0;
    int cnt=1,a,b;
    // 判断左右
    a=x;
    b=y;
    while(b--) {
        if(chess[a][b]==T)
            cnt++;
        else
            break;
    }
    a=x;
    b=y;
    while(b++&&b<N) {
        if(chess[a][b]==T)
            cnt++;
        else
            break;
    }
    if(cnt>=5)
        return 1;
    //判断上下
    cnt=1;
    a=x;
    b=y;
    while(a--) {
        if(chess[a][b]==T)
            cnt++;
        else
            break;
    }
    a=x;
    b=y;
    while(a++&&a<N) {
        if(chess[a][b]==T)
            cnt++;
        else
            break;
    }
    if(cnt>=5)
        return 1;
    //判断左上右下
    cnt=1;
    a=x;
    b=y;
    while(a--&&b--) {
        if(chess[a][b]==T)
            cnt++;
        else
            break;
    }
    a=x;
    b=y;
    while(a++&&b++&&a<N&&b<N) {
        if(chess[a][b]==T)
            cnt++;
        else
            break;
    }
    if(cnt>=5)
        return 1;
    //判断右上左下
    cnt=1;
    a=x;
    b=y;
    while(a--&&b++&&b<N) {
        if(chess[a][b]==T)
            cnt++;
        else
            break;
    }
    a=x;
    b=y;
    while(a++&&b--&&a<N) {
        if(chess[a][b]==T)
            cnt++;
        else
            break;
    }
    if(cnt>=5)
        return 1;
    if(sum==14*14)
        return 2;
    return 0;
}
void AI(int *x,int *y) {
    int score[N][N];
    memset(score,0,sizeof(score));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(chess[i][j]==' ')
                score[i][j]=mark(i,j);
        }
    }
    int flag=0,t1=0,t2=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(score[i][j]>flag) {
                t1=i;
                t2=j;
            }
        }
    }
    *x=t1;
    *y=t2;
    sum++;
    chess[t1][t2]=player2;
    gotoxy(0,0);
    qipan();
}
int mark(int x,int y) {
    int a,b,cnt=0,s=0;
    // 判断左右
    a=x;
    b=y;
    while(b--) {
        if(chess[a][b]==player1)
            cnt++;
        else
            break;
    }
    a=x;
    b=y;
    while(b++&&b<N) {
        if(chess[a][b]==player1)
            cnt++;
        else
            break;
    }
    if(cnt>s)
        s=cnt;
    //判断上下
    //cnt=0;
    a=x;
    b=y;
    while(a--) {
        if(chess[a][b]==player1)
            cnt++;
        else
            break;
    }
    a=x;
    b=y;
    while(a++&&a<N) {
        if(chess[a][b]==player1)
            cnt++;
        else
            break;
    }
    if(cnt>s)
        s=cnt;
    //判断左上右下
    //cnt=0;
    a=x;
    b=y;
    while(a--&&a--) {
        if(chess[a][b]==player1)
            cnt++;
        else
            break;
    }
    a=x;
    b=y;
    while(a++&&b++&&a<N&&b<N) {
        if(chess[a][b]==player1)
            cnt++;
        else
            break;
    }
    if(cnt>s)
        s=cnt;
    //判断右上左下
    //cnt=0;
    a=x;
    b=y;
    while(a--&&b++&&b<N) {
        if(chess[a][b]==player1)
            cnt++;
        else
            break;
    }
    a=x;
    b=y;
    while(a++&&b--&&a<N) {
        if(chess[a][b]==player1)
            cnt++;
        else
            break;
    }
    if(cnt>s)
        s=cnt;
    return s;
}

