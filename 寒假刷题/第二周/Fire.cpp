#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
char Map[maxn][maxn];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int r, c;
struct pos
{
    int x, y;
};
bool isescaped(queue<pos> &people)//用来判定有没有逃出去
{
    queue<pos> newp = people;
    while (newp.size())
    {
        pos it = newp.front();
        newp.pop();
        if (it.x == 0 || it.x == r - 1 || it.y == 0 || it.y == c - 1)
            return true;
    }
    return false;
}
void updataPeople(queue<pos> &people)//更新people的路径
{
    queue<pos> newp;
    pos temp;
    while (people.size())
    {
        pos it = people.front();
        people.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = it.x + dx[i], ny = it.y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && Map[nx][ny] == '.')
            {
                Map[nx][ny] = 'J';
                temp.x = nx, temp.y = ny;
                newp.push(temp);
            }
        }
    }
    people = newp;
}
void updataFire(queue<pos> &fire)//更新fire的路径
{
    queue<pos> newp;
    pos temp;
    while (fire.size())
    {
        pos it = fire.front();
        fire.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = it.x + dx[i], ny = it.y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && (Map[nx][ny] == '.' || Map[nx][ny] == 'J'))
            {
                Map[nx][ny] = 'F';
                temp.x = nx, temp.y = ny;
                newp.push(temp);
            }
        }
    }
    fire = newp;
}
int main(void)
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> r >> c;
        pos p, f;
        queue<pos> people, fire; //两个队列来记录人和火的状态
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                cin >> Map[i][j];
                if (Map[i][j] == 'J') //找到人的坐标
                {
                    p.x = i;
                    p.y = j;
                    people.push(p);
                }
                if (Map[i][j] == 'F') //找到火的坐标
                {
                    f.x = i;
                    f.y = j;
                    fire.push(f);
                }
            }
        int step = 1;
        while (people.size())
        {
            if (isescaped(people)) //判定有没有逃出去
            {
                cout << step << endl;
                break;
            }
            step++;//步数+1
            updataFire(fire); //更新火的状态
            updataPeople(people); //更新人的状态
        }
        if (people.size() == 0)//如果人都没了，说明被火烧死了
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}