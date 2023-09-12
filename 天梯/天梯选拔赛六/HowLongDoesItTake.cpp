//拓扑排序
// How Long Does It Take (25 分)
// Given the relations of all the activities of a project, you are supposed to find the earliest completion time of the project.

// Input Specification:
// Each input file contains one test case. Each case starts with a line containing two positive integers N (≤100), the number of activity check points (hence it is assumed that the check points are numbered from 0 to N−1), and M, the number of activities. Then M lines follow, each gives the description of an activity. For the i-th activity, three non-negative numbers are given: S[i], E[i], and L[i], where S[i] is the index of the starting check point, E[i] of the ending check point, and L[i] the lasting time of the activity. The numbers in a line are separated by a space.

// Output Specification:
// For each test case, if the scheduling is possible, print in a line its earliest completion time; or simply output "Impossible".
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int in[maxn], graph[maxn][maxn];
int cost[maxn];
int n, m;
void init()
{
    cin >> n >> m;
    memset(graph, -1, sizeof(graph));
    for (int i = 0, x, y, z; i < m; i++)
    {
        cin >> x >> y >> z;
        graph[x][y] = z;
        in[y]++;
    }
}
bool solove()
{
    queue<int> q;
    int x;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
            q.push(i), in[i]--;
    }
    while (q.size())
    {
        x = q.front();
        q.pop();
        bool updata = false;
        for (int i = 0; i < n; i++)
        {
            if (graph[x][i] >= 0)
            {
                updata = true;
                if (--in[i] == 0)
                    q.push(i), in[i]--;
                cost[i] = max(cost[i], cost[x] + graph[x][i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (in[i] > 0)
            return false;
    return true;
}
int main()
{
    init();
    if (solove())
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, cost[i]);
        cout << ans;
    }
    else
        cout << "Impossible";
}