#include <cstdio>
#include <queue>
#include <map>
using namespace std;
int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        map<int, priority_queue<int>> m;
        int day, value;
        while (n--)
        {
            scanf("%d%d", &value, &day);
            m[day].push(value);
        }
        int ans = 0;
        map<int, priority_queue<int>>::reverse_iterator it = m.rbegin(), end = m.rend(); //从最后一天开始卖
        priority_queue<int> que;
        for (int n = it->first; n >= 1; n--) //递减遍历天数
        {
            if (it != end && it->first >= n) //如果保质期大于现在的天数
            {
                while (it->second.size())
                    que.push(it->second.top()), it->second.pop();
                it++;
            }
            if (que.size())
                ans += que.top(), que.pop();
        }
        printf("%d\n", ans);
    }
}