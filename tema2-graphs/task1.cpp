#include <vector>

#include "./util.h"

using namespace std;

bool hasCycleUtil(vector<vector<int>>& graph, int node, vector<bool> visited, vector<bool> path) {

    // Mark the current node as visited.
    visited[node] = true;
    // Mark the current node as part of the path.
    path[node] = true;

    // Iterate over all the neighbors of the current node.
    for (auto neighbor : graph[node]) {

        // If a neighbor has not been visited.
        if (!visited[neighbor]) {

            // Call the function with the neighbor node. If it returns true, a cycle has been found.
            if (hasCycleUtil(graph, neighbor, visited, path)) {
                return true;
            }
        }
        else if (path[neighbor]) {

            // If the neighbor node is part of the path, a cycle exists.
            return true;
        }
    }

    // Mark the current node as not being part of the path anymore.
    path[node] = false;
    return false;
}

/**
 * @brief Task 1 function to detect if a graph is cyclic or not.
 * @param graph The graph.
 * @return 0 = cyclic, 1 = not cyclic.
 */
int hasCycle(vector<vector<int>> graph) {

    // Get the number of nodes.
    int n = graph.size();

    // Initialize a vector that keeps track of visited nodes.
    vector<bool> visited(n, false);
    // Initialize a vector that keeps track of the path in the current traversal.
    vector<bool> path(n, false);

    for (auto i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(graph, i, visited, path)) {
                return 1;
            }
        }
    }

    return 0;
}