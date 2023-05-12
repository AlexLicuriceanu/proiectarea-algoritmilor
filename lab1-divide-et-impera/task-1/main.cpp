#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, x;
    vector<int> v;

    void read_input() {
        ifstream fin("in");
        fin >> n;
        for (int i = 0, e; i < n; i++) {
            fin >> e;
            v.push_back(e);
        }
        fin >> x;
        fin.close();
    }

    int find_first() {
        // Cautati prima pozitie pe care se afla valoarea x
        // In cazul in care x nu apare in sir, returnati -1

        int left = 0, right = n-1, mid, result = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (v[mid] >= x) {
                right = mid-1;
                result = mid;
            }
            else {
                left = mid+1;
            }
        }

        return (result != -1 && v[result] == x) ? result : -1;
    }

    int find_last() {
        // Cautati ultima pozitie pe care se afla valoarea x
        // In cazul in care x nu apare in sir, returnati -1

        int left = 0, right = n-1, mid, result = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (v[mid] <= x) {
                left = mid+1;
                result = mid;
            }
            else {
                right = mid-1;
            }
        }

        return (result != -1 && v[result] == x) ? result : -1;
    }

    int get_result() {
        // Calculati numarul de aparitii ale lui x in vectorul v

        int first = find_first();
        int last = find_last();
        if (first == -1 || last == -1) {
            return 0;
        }
        return last - first + 1;
    }

    void print_output(int result) {
        ofstream fout("out");
        fout << result;
        fout.close();
    }
};

// [ATENTIE] NU modifica functia main!
int main() {
    // * se aloca un obiect Task pe heap
    // (se presupune ca e prea mare pentru a fi alocat pe stiva)
    // * se apeleaza metoda solve()
    // (citire, rezolvare, printare)
    // * se distruge obiectul si se elibereaza memoria
    auto* task = new (nothrow) Task(); // hint: cppreference/nothrow
    if (!task) {
        cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
