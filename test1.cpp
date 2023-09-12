#include <iostream>
#include <vector>
#include <climits>

struct Edge {
    int to;
    int weight;
};

using Graph = std::vector<std::vector<int>>;

std::vector<Edge> primMST(const Graph& graph, int n, int& totalWeight) {
    std::vector<Edge> mst;
    std::vector<bool> visited(n, false);
    std::vector<int> minWeight(n, INT_MAX);

    minWeight[0] = 0;
    totalWeight = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || minWeight[j] < minWeight[u])) {
                u = j;
            }
        }

        visited[u] = true;

        if (u != 0) {
            mst.push_back({u, minWeight[u]});
            totalWeight += minWeight[u];
        }

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] < minWeight[v]) {
                minWeight[v] = graph[u][v];
            }
        }
    }

    return mst;
}

int main() {
    int n = 5;
    Graph arr = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int totalWeight = 0;
    std::vector<Edge> mst = primMST(arr, n, totalWeight);

    std::cout << "最小生成树的边和权重：" << std::endl;
    for (const Edge& edge : mst) {
        std::cout << "Edge: " << edge.to << " Weight: " << edge.weight << std::endl;
    }

    std::cout << "最小生成树的权重之和: " << totalWeight << std::endl;

    return 0;
}
