#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "./util.h"

using namespace std;

int check_task1() {

    int taskScore = 0;
    int individualTaskPoints = TASK1_MAX_POINTS / TASK1_TESTS_NUMBER;


    for (int task = 1; task <= TASK1_TESTS_NUMBER; task++) {

        // Set up file paths.
        string inputFile = string(TASK1_TESTS_PATH) + "test" + to_string(task) + ".in";
        string refFile = string(TASK1_TESTS_PATH) + "test" + to_string(task) + ".out";
        string outputFile = string(TASK1_OUT_PATH) + "test" + to_string(task) + ".out";

        // Set up file streams.
        ifstream fin(inputFile);
        ofstream fout(outputFile);

        // Read number of nodes, number of edges.
        int n, m;
        fin >> n >> m;

        // Read the graph.
        vector<vector<int>> graph(n+1);

        for (int i = 0; i < m; i++) {
            int source, destination;
            fin >> source >> destination;
            graph[source].push_back(destination);
        }

        // Call the task's function.
        int result = hasCycle(graph);
        // Output the result.
        fout << result;

        // Get the expected result.
        int expected;
        ifstream fin_ref(refFile);
        fin_ref >> expected;

        // Check if the computed result is the same as the expected result.
        if (result == expected) {
            // Add points.
            taskScore += individualTaskPoints;
        }

        // Close the files for the current test.
        fin.close();
        fout.close();
        fin_ref.close();
    }

    return taskScore;
}

int check_task2() {
    int taskScore = 0;
    int individualTaskPoints = TASK2_MAX_POINTS / TASK2_TESTS_NUMBER;


    for (int task = 1; task <= TASK2_TESTS_NUMBER; task++) {

        // Set up file paths.
        string inputFile = string(TASK2_TESTS_PATH) + "test" + to_string(task) + ".in";
        string refFile = string(TASK2_TESTS_PATH) + "test" + to_string(task) + ".out";
        string outputFile = string(TASK2_OUT_PATH) + "test" + to_string(task) + ".out";

        // Set up file streams.
        ifstream fin(inputFile);
        ofstream fout(outputFile);

        // Read number of nodes, number of edges, source node.
        int n, m, s;
        fin >> n >> m >> s;

        // Read the graph.
        vector<vector<int>> graph(n+1);

        for (int i = 0; i < m; i++) {
            int source, destination, cost;
            fin >> source >> destination >> cost;

            // TODO
            //graph[source].push_back(destination);
        }

        // Call the task's function.
        // TODO
        // Output the result.
        //fout << result;

        // Get the expected result.
        int expected;
        ifstream fin_ref(refFile);
        fin_ref >> expected;

        // Check if the computed result is the same as the expected result.
        //if (result == expected) {
            // Add points.
        //    taskScore += individualTaskPoints;
        //}

        // Close the files for the current test.
        fin.close();
        fout.close();
        fin_ref.close();
    }

    return taskScore;
}

int check_task3() {

    return 0;
}



int main(int argc, char **argv) {

    if (argc > 2) {
        cout << R"(Usage: "./checker" or "./checker <1 | 2 | 3>")" << endl;
        cout << "Where: 1 = task 1, 2 = task 2, 3 = task 3." << endl;
    }

    // Test all.
    if (argc == 1) {

        // Calculate the score for each task.
        int task1Score = check_task1();
        int task2Score = check_task2();
        int task3Score = check_task3();

        // Calculate the total score.
        int totalScore = task1Score + task2Score + task3Score;

        // Output scores.
        cout << "Task 1: " << task1Score << "/" << TASK1_MAX_POINTS << "p" << endl;
        cout << "Task 2: " << task2Score << "/" << TASK2_MAX_POINTS << "p" << endl;
        cout << "Task 3: " << task3Score << "/" << TASK3_MAX_POINTS << "p" << endl << endl;
        cout << "Total: " << totalScore << "/" << MAX_POINTS << "p" << endl;
        return 0;
    }

    // Get the task number to test.
    string taskNumber = argv[1];

    // Handle task 1.
    if (taskNumber == "1") {

        int task1Score = check_task1();
        cout << "Task 1: " << task1Score << "/" << TASK1_MAX_POINTS << "p" << endl;
        return 0;
    }

    // Handle task 2.
    if (taskNumber == "2") {

        int task2Score = check_task2();
        cout << "Task 2: " << task2Score << "/" << TASK2_MAX_POINTS << "p" << endl;
        return 0;
    }

    // Handle task 3.
    if (taskNumber == "3") {

        int task3Score = check_task3();
        cout << "Task 3: " << task3Score << "/" << TASK3_MAX_POINTS << "p" << endl;
        return 0;
    }

    cout << "Invalid problem number." << endl;
    return 0;
}