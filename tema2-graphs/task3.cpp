#include <vector>
#include "./util.h"

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