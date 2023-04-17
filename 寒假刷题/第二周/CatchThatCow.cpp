#include <iostream>
#include <queue>
using namespace std;
int n, k;
const int maxn = 110000;
struct node
{
    int pos, step;
};
bool visited[maxn] = {false};
int main(void)
{
    cin >> n >> k;
    queue<node> que;
    node front = {n, 0};
    node temp;
    visited[front.pos] = true;
    que.push(front);
    while (que.size())
    {
        front = que.front();
        que.pop();
        if (front.pos == k)
        {
            cout << front.step << endl;
            return 0;
        }
        ////向后走一步
        temp = front;
        temp.pos--, temp.step++;
        if (temp.pos >= 0 && visited[temp.pos] == false) //如果该点没有来过,且位置不能越界
        {
            que.push(temp);           //入队
            visited[temp.pos] = true; //该点已经来过
        }
        //向前走一步
        if (front.pos < k)
        {
            temp = front;
            temp.pos++, temp.step++;
            if (temp.pos < maxn && visited[temp.pos] == false) //如果该点没有来过,且位置不能越界
            {
                que.push(temp);           //入队
                visited[temp.pos] = true; //该点已经来过
            }
            //传送
            temp = front;
            temp.pos *= 2, temp.step++;                        //
            if (temp.pos < maxn && visited[temp.pos] == false) //如果该点没有来过,且位置不能越界
            {
                que.push(temp);           //入队
                visited[temp.pos] = true; //该点已经来过
            }
        }
    }
    return 0;
}