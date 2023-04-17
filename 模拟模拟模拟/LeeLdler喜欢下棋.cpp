#include <iostream>
#include <cstring>
using namespace std;
char G[3][3];
char winner(int i, int j, char x)
{
    char dx = x == 'o' ? 'x' : 'o';
    int count[4] = {1, 1, 1, 1};
    int d;
    for (d = 1; d <= 2; d++)
    {
        if (j - d >= 0 && G[i][j - d] == dx || j + d < 3 && G[i][j + d] == dx)
        {
            count[0] = 0;
            break;
        }
        if (j - d >= 0 && G[i][j - d] == x)
            count[0]++;
        if (j + d < 3 && G[i][j + d] == x)
            count[0]++;
    }
    for (d = 1; d <= 2; d++)
    {
        if (i - d >= 0 && G[i - d][j] == dx || i + d < 3 && G[i + d][j] == dx)
        {
            count[1] = 0;
            break;
        }
        if (i - d >= 0 && G[i - d][j] == x)
            count[1]++;
        if (i + d < 3 && G[i + d][j] == x)
            count[1]++;
    }
    for (d = 1; d <= 2; d++)
    {
        if (i - d >= 0 && j + d < 3 && G[i - d][j + d] == dx || i + d < 3 && j - d >= 0 && G[i + d][j - d] == dx)
        {
            count[2] = 0;
            break;
        }
        if (i - d >= 0 && j + d < 3 && G[i - d][j + d] == x)
            count[2]++;
        if (i + d < 3 && j - d >= 0 && G[i + d][j - d] == x)
            count[2]++;
    }
    for (d = 1; d <= 2; d++)
    {
        if (i + d < 3 && j + d < 3 && G[i + d][j + d] == dx || i - d >= 0 && j - d >= 0 && G[i - d][j - d] == dx)
        {
            count[3] = 0;
            break;
        }
        if (i + d < 3 && j + d < 3 && G[i + d][j + d] == x)
            count[3]++;
        if (i - d >= 0 && j - d >= 0 && G[i - d][j - d] == x)
            count[3]++;
    }
    if (i == 0 && j == 1 || i == 1 && j == 2 || i == 2 && j == 1 || i == 1 && j == 0)
        count[2] = count[3] = 0;
    int book[4] = {0};
    for (int i = 0; i < 4; i++)
        book[count[i]]++;
    //
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //         cout << G[i][j]<<" ";
    //     cout << endl;
    // }
    // cout << i << j << ":";
    // for (int i = 0; i < 4; i++)
    //     cout << count[i];
    // cout << endl;
    //
    if (book[3] >= 1 || book[2] >= 2)
    {
        return x;
    }
    return '.';
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        char count[256] = {0};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> G[i][j];
                count[G[i][j]]++;
            }
        }
        char LeeLdler, Ai;
        cin >> LeeLdler;
        Ai = LeeLdler == 'o' ? 'x' : 'o';
        if (abs(count['o'] - count['x']) >= 2)
        {
            cout << "wrong!" << endl;
            continue;
        }
        if (abs(count['o'] - count['x']) >= 1)
        {
            if (count['o'] > count['x'] && LeeLdler == 'o' || count['x'] > count['o'] && LeeLdler == 'x')
            {
                cout << "wrong!" << endl;
                continue;
            }
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (G[i][j] == '.')
                {
                    G[i][j] = LeeLdler;
                    if (winner(i, j, LeeLdler) == LeeLdler)
                    {
                        cout << "LeeLdler win!" << endl;
                        goto end;
                    }
                    G[i][j] = '.';
                }
            }
        cout << "Cannot win!" << endl;
    end:;
    }
    return 0;
}