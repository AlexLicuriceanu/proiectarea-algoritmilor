#include <vector>

#include "./util.h"

using namespace std;

bool hasCycleUtil(vector<vector<int>>& graph, int node, vector<bool> visited, vector<bool> recursionStack) {
    visited[node] = true;
    recursionStack[node] = true;

    for (auto neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (hasCycleUtil(graph, neighbor, visited, recursionStack)) {
                return true;
            }
        }
        else if (recursionStack[neighbor]) {
            return true;
        }
    }

    recursionStack[node] = false;
    return false;
}

int hasCycle(vector<vector<int>> graph) {
    int n = graph.size();

    vector<bool> visited(n, false);
    vector<bool> recursionStack(n, false);

    for (auto i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(graph, i, visited, recursionStack)) {
                return 1;
            }
        }
    }

    return 0;
}