#include <iostream>
#include <vector>
#include <fstream>

#define INPUT_FILE_NAME "./date.in"
#define OUTPUT_FILE_NAME "./date.out"
#define INF -1

using namespace std;

/**
 * @brief Task 3 function to find the shortest path from a source node in a weighted graph
 * with weights less or equal to 30.
 * @param source Index of the source node.
 * @param graph The graph.
 * @return Vector with the minimum cost to reach every node from the source node.
 */
vector<int> shortestPath2(int source, vector<vector<pair<int, int>>> graph) {
    int n = graph.size();

    vector<int> dist(n, INF);
    dist[source] = 0;

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
    vector<int> result = shortestPath2(s, graph);
    // Output the result.
    for (unsigned int i = 1; i < result.size(); i++) {
        fout << result[i] << " ";
    }

    // Close the files for the current test.
    fin.close();
    fout.close();

    return 0;
}