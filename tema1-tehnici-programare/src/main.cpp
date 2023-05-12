#include <iostream>
#include "Solution.h"

int main() {

    std::cout << "Enter a number to run a problem:" << std::endl;
    std::cout << "0 = All,\n1 = Divide et Impera,\n2 = Greedy,\n3 = Dynamic Programming,\n4 = Backtracking.\nRun:";

    int problemNumber = -1;
    std::cin >> problemNumber;

    if (problemNumber == 0) {

        // Run all problems.
        auto solution1 = new Solution1;
        solution1->run();

        auto solution2 = new Solution2;
        solution2->run();

        auto solution3 = new Solution3;
        solution3->run();

        auto solution4 = new Solution4;
        solution4->run();

        return 0;
    }

    if (problemNumber == 1) {

        // Run problem 1.
        auto solution1 = new Solution1;
        solution1->run();
        return 0;
    }

    if (problemNumber == 2) {

        // Run problem 2.
        auto solution2 = new Solution2;
        solution2->run();
        return 0;
    }

    if (problemNumber == 3) {

        // Run problem 3.
        auto solution3 = new Solution3;
        solution3->run();
        return 0;
    }

    if (problemNumber == 4) {

        // Run problem 4.
        auto solution4 = new Solution4;
        solution4->run();
        return 0;
    }

    std::cout << "Invalid problem number entered, exiting." << std::endl;

    return 0;
}