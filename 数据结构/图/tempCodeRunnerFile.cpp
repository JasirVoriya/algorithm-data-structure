#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int maxn = 1e2;
struct ArcNode
{
    int v;
    //索引
    int adjvex;
    ArcNode *next_arc = nullptr;
    int data;
};
typedef struct VNode
{
    int v;
    ArcNode *fisrt_arc = nullptr;
} AdjList[maxn];
struct ALGraph
{
    AdjList vertices;
    int max_v, max_n;
    //找下标
    int LocateVex(int v)
    {
        for (int i = 0; i < max_v; i++)
        {
            if (vertices[i].v == v)
                return i;
        }
    }
    int GetV(int adjvex)
    {
        return vertices[adjvex].v;
    }
    void _dfs(bool *vis, int v)
    {
        cout << v, vis[v] = true;
        int w;
        for (ArcNode *p = vertices[LocateVex(v)].fisrt_arc; p != nullptr; p = p->next_arc)
        {
            w = GetV(p->adjvex);
            if (!vis[w])
                _dfs(vis, w);
        }
    }
    void DFS(int v)
    {
        bool vis[maxn] = {false};
        _dfs(vis, v);
    }
    void _bfs(bool *vis, int v)
    {
        queue<int> que;
        cout << v, que.push(v), vis[v] = true;
        while (que.size())
        {
            int v = que.front();
            que.pop();
            for (ArcNode *p = vertices[LocateVex(v)].fisrt_arc; p != nullptr; p = p->next_arc)
            {
                if (!vis[GetV(p->adjvex)])
                    cout << GetV(p->adjvex), que.push(GetV(p->adjvex)), vis[GetV(p->adjvex)] = true;
            }
        }
    }
    void BFS(int v)
    {
        bool vis[maxn] = {false};
        _bfs(vis, v);
    }
    void print()
    {
        for (int i = 0; i < max_v; i++)
        {
            cout << vertices[i].v << ":";
            for (ArcNode *it = vertices[i].fisrt_arc; it != nullptr; it = it->next_arc)
                cout << GetV(it->adjvex);
            cout << endl;
        }
    }
};
bool CreateUDG(ALGraph &G)
{
    cin >> G.max_v >> G.max_n;
    for (int k = 0; k < G.max_v; k++)
        cin >> G.vertices[k].v;
    for (int k = 0, v1, v2; k < G.max_n; k++)
    {
        cin >> v1 >> v2;
        auto p1 = new ArcNode, p2 = new ArcNode;
        v1 = G.LocateVex(v1), v2 = G.LocateVex(v2);
        p1->adjvex = v2, p2->adjvex = v1;
        p1->next_arc = G.vertices[v1].fisrt_arc, G.vertices[v1].fisrt_arc = p1;
        p2->next_arc = G.vertices[v2].fisrt_arc, G.vertices[v2].fisrt_arc = p2;
    }
    return true;
}
int main(void)
{
    ALGraph G;
    CreateUDG(G);
    G.DFS(1);
    cout << endl;
    G.BFS(1);
    cout << endl;
    return 0;
}