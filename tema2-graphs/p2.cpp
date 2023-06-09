#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

#define INPUT_FILE_NAME "./date.in"
#define OUTPUT_FILE_NAME "./date.out"
#define INF -1

using namespace std;

void topologicalSortUtil(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited, stack<int>& sorted) {

    // Mark the current node as visited.
    visited[node] = true;

    // Iterate over each node adjacent to the current node.
    for (auto edge : graph[node]) {

        auto neighbor = edge.first;

        // Check if the adjacent node has been visited.
        if (!visited[neighbor]) {

            // If it was not visited, call the topological sort function, similar to a DFS traversal.
            topologicalSortUtil(neighbor, graph, visited, sorted);
        }
    }

    // Put the node on the stack, ensuring that the nodes with no incoming edges
    // are pushed first.
    sorted.push(node);
}

/**
 * @brief Task 2 function to find the shortest path from a source node in a weighted graph.
 * @param source Index of the source node.
 * @param graph The graph.
 * @return Vector with the minimum cost to reach every node from the source node.
 */
vector<int> shortestPath1(int source, vector<vector<pair<int, int>>> graph) {

    // Get number of nodes.
    int n = graph.size();

    // Set cost to each node as infinity.
    vector<int> dist(n, INF);
    // Cost to go to the source is 0.
    dist[source] = 0;

    // Initialize vector of visited nodes.
    vector<bool> visited(n, false);
    // Stack to store the nodes in topological order.
    stack<int> sorted;

    // Iterate all nodes in the graph, populate the "sorted" stack
    // with the nodes in topological order.
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, graph, visited, sorted);
        }
    }

    // Bellman-Ford.
    while (!sorted.empty()) {
        auto node = sorted.top();
        sorted.pop();

        if (dist[node] != INF) {
            for (auto edge : graph[node]) {
                auto neighbor = edge.first;
                auto cost = edge.second;

                if (dist[node] + cost < dist[neighbor] || dist[neighbor] == INF) {
                    dist[neighbor] = dist[node] + cost;
                }
            }
        }
    }

    return dist;
}

int main() {

    // Read input file.
    string inputFile = string(INPUT_FILE_NAME);
    // Set up output file.
    string outputFile = string(OUTPUT_FILE_NAME);

    // File streams.
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    // Read number of nodes, number of edges.
    int n, m, s;
    fin >> n >> m >> s;

    // Read the graph.
    vector<vector<pair<int, int>>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int source, destination, cost;
        fin >> source >> destination >> cost;
        graph[source].emplace_back(destination, cost);
    }

    // Call the task's function.
    vector<int> result = shortestPath1(s, graph);
    // Output the result.
    for (unsigned int i = 1; i < result.size(); i++) {
        fout << result[i] << " ";
    }

    // Close the files for the current test.
    fin.close();
    fout.close();

    return 0;
}