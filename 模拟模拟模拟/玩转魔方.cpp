#include <bits/stdc++.h>
using namespace std;
int square[6][4];
bool win()
{
    for (int i = 0; i < 6; i++)
        if (!(square[i][0] == square[i][1] && square[i][1] == square[i][2] && square[i][2] == square[i][3]))
            return false;
    return true;
}
void frontright()
{
    int temp[2]={square[0][2],square[0][3]};
    square[0][2]=square[4][3],square[0][3]=square[4][1];
    square[4][3]=square[2][1],square[4][1]=square[2][0];
    square[2][1]=square[5][0],square[2][0]=square[5][2];
    
}
void frontleft()
{
    int temp[2] = {square[1][0], square[1][1]};
    square[1][0] = square[5][0], square[1][1] = square[5][1];
    square[5][0] = square[3][0], square[5][1] = square[3][1];
    square[3][0] = square[4][0], square[3][1] = square[4][1];
    square[4][0] = temp[0], square[4][1] = temp[1];
}
void leftup()
{
    int temp[2]={square[0][0],square[0][2]};
    square[0][0] = square[1][0], square[0][2] = square[1][2];
    square[1][0] = square[2][0], square[1][2] = square[2][2];
    square[2][0] = square[3][0], square[2][2] = square[3][2];
    square[3][0] = temp[0], square[3][2] = temp[1];

}
void leftdown()
{
    int temp[2]={square[0][0],square[0][2]};
    square[0][0] = square[3][0], square[0][2] = square[3][2];
    square[3][0] = square[2][0], square[3][2] = square[2][2];
    square[2][0] = square[1][0], square[2][2] = square[1][2];
    square[1][0] = temp[0], square[1][2] = temp[1];
}
void backleft()
{
    int temp[2]={square[0][0],square[0][1]};
    square[0][0]=square[4][0],square[0][1]=square[4][1];
    square[4][0]=square[2][0],square[4][1]=square[2][1];
    square[2][0]=square[5][0],square[2][1]=square[5][1];
}
void backright()
{
}
bool solove()
{
    if (win())
        return true;
    if (win())
        return true;
    
}
int main(void)
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 4; j++)
                cin >> square[i][j];
    }
    return 0;
}