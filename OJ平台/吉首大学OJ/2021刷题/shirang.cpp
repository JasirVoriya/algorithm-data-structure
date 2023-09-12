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
    int x;//������
    int y;//������
};
stack<zuobiao>P1,P2;
int sum=0;//���ӵ�����
char chess[N][N];//����
char player1='1',player2='2';//p1,p2��ҵ�����
void qipan();//��ӡ����
void Menu();//�˵�
char choosemode();//ѡ��ģʽ
void start();//��ʼ
int Rechess(char player);//����
void ReGame();//����һ��
//���
void put1(int *x,int *y);//���1����
void put2(int *x,int *y);//���2����
//ɵ�ϵ���
void AI(int *x,int *y);
int mark(int x,int y);
int isGameOver(int x,int y);//�ж���Ϸ����
void endGame();//��Ϸ����
void gotoxy(int i,int j) { //�ƶ���꣨����˸��꣩
    COORD position= {i,j};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);//�ƶ����
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//���ع��
}
/*void gotoxyz(int i,int j) { //�ƶ���꣨��˸��꣩
    COORD position= {i,j};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);//�ƶ����
    CONSOLE_CURSOR_INFO cursor_info = {1, 1};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//��ʾ���
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
    printf("\t\t *     ��л��������!    *\n");
    printf("\t\t *                      *\n");
    printf("\t\t ************************\n");
}
void ReGame() {
    printf("\t\t ************************\n");
    printf("\t\t *                      *\n");
    printf("\t\t *     �Ƿ�����һ�֣�   *\n");
    printf("\t\t *      y   or   n      *\n");
    printf("\t\t ************************\n");
}
void Menu() {
    printf("\t\t ************************\n");
    printf("\t\t *        ������        *\n");
    printf("\t\t *                      *\n");
    printf("\t\t *       ��ʼ��Ϸ       *\n");
    printf("\t\t ************************\n");
    printf("\t\t      ���������ʼ��Ϸ   \n");
}
char choosemode() {
    int a1=N/2,a2=N/2,b1=N/2,b2=N/2;
    printf("\t\t ************************\n");
    printf("\t\t *      1.���˶�ս      *\n");
    printf("\t\t *                      *\n");
    printf("\t\t *      2.�˻���ս      *\n");
    printf("\t\t ************************\n");
    printf("\t\t ��ѡ��ģʽ��\n");
    int t;
    t=getch();
    while(t!='1'&&t!='2') {
        printf("�������,����������:\n");
        t=getch();
    }
    system("mode con cols=100 lines=40");
    if(t=='1') {
        while(1) {
            /* ���˶�ս */
            put1(&a1,&a2);//P1�غ�
            if(isGameOver(a1,a2)==1) {
                printf("���1ʤ��!!!\n");//�Ծֽ���
                break;
            }
            put2(&b1,&b2);//P2�غ�
            if(isGameOver(b1,b2)==1) {
                printf("���2ʤ��!!!\n");//�Ծֽ���
                break;
            }
            if(isGameOver(b1,b2)==2) {
                printf("ƽ��!!!\n");//�Ծֽ���
                break;
            }
        }
    } else if(t=='2') {
        while(1) {
            /* �˻���ս */
            put1(&a1,&a2);//P1�غ�
            if(isGameOver(a1,a2)==1) {
                printf("���1ʤ��!!!\n");//�Ծֽ���
                break;
            }
            AI(&b1,&b2);//ɵ�ϵ��Իغ�
            if(isGameOver(b1,b2)==1) {
                printf("ɵ�ϵ���ʤ��!!!\n");//�Ծֽ���
                break;
            }
            if(isGameOver(b1,b2)==2) {
                printf("ƽ��!!!\n");//�Ծֽ���
                break;
            }
        }
    }
    ReGame();
    t=getch();
    while(t!='y'&&t!='n') {
        printf("���������������\n");
        t=getch();
    }
    return t;
}
void put1(int *x,int *y) {
    int a=*x,b=*y,ff=0;
    char T;
    zuobiao Ply1;//��¼p1������
    T=chess[a][b];
    chess[*x][*y]=player1;
    gotoxy(0,0);
    qipan();
    while(1) {
        gotoxy(100,0);
        printf("                                                      \n");
        int t;
        t=getch();
        // 72��  75��  80��  77��
        if(t==13) {
            if(T!=' ') {
                //gotoxy(100,20);
                printf("p1�㲻��������!");
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
            switch(t) {  // �� �� �� �ҿ��Ʒ��� �س�����
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
        switch(t) {   // w,s,a,d���Ʒ���   �ո�����
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
                printf("p2�㲻��������!");
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
                strcpy(p[i][j],"��\0");
            }
            if(chess[i][j]==player2) {
                strcpy(p[i][j],"��\0");
            }
        }
    }
    printf("                                   ������                            \n");
    printf("                                                                     \n");
    printf("    p1 ���� ���� ���� ���� �س�����          p2 w �� s�� a�� d�� �ո�����\n");
    printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");
    printf("       ���������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ�������\n");
    for(int i=0,j=0; i<N-1; i++,j++) {
        printf("     %2ld��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%d\n",j,p[i][0],p[i][1],p[i][2],p[i][3],p[i][4],p[i][5],p[i][6],p[i][7],p[i][8],p[i][9],p[i][10],p[i][11],p[i][12],p[i][13],p[i][14],j);
        printf("       ���������੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤�����੤������\n");
    }
    printf("     14��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%3s��%d\n",p[14][0],p[14][1],p[14][2],p[14][3],p[14][4],p[14][5],p[14][6],p[14][7],p[14][8],p[14][9],p[14][10],p[14][11],p[14][12],p[14][13],p[14][14],14);
    printf("       ���������ة������ة������ة������ة������ة������ة������ة������ة������ة������ة������ة������ة������ة������ة�������\n");
    printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");
}
int isGameOver(int x,int y) {
    char T=chess[x][y];
    if(T==' ')
        return 0;
    int cnt=1,a,b;
    // �ж�����
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
    //�ж�����
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
    //�ж���������
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
    //�ж���������
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
    // �ж�����
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
    //�ж�����
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
    //�ж���������
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
    //�ж���������
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

