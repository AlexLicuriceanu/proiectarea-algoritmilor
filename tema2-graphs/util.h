#ifndef TEMA2_GRAPHS_UTIL_H
#define TEMA2_GRAPHS_UTIL_H

#include <vector>

#define INF -1

#define TASK1_TESTS_PATH "./pb1_tests/"
#define TASK2_TESTS_PATH "./pb2_tests/"
#define TASK3_TESTS_PATH "./pb3_tests/"

#define TASK1_OUT_PATH "./pb1_out/"
#define TASK2_OUT_PATH "./pb2_out/"
#define TASK3_OUT_PATH "./pb3_out/"

#define TASK1_TESTS_NUMBER 10
#define TASK2_TESTS_NUMBER 10
#define TASK3_TESTS_NUMBER 10

#define TASK1_MAX_POINTS 30
#define TASK2_MAX_POINTS 40
#define TASK3_MAX_POINTS 30
#define MAX_POINTS TASK1_MAX_POINTS + TASK2_MAX_POINTS + TASK3_MAX_POINTS

using namespace std;

int hasCycle(vector<vector<int>> graph);
vector<int> shortestPath1(int source, vector<vector<pair<int, int>>> graph);
vector<int> shortestPath2(int source, vector<vector<pair<int, int>>> graph);

#endif //TEMA2_GRAPHS_UTIL_H
