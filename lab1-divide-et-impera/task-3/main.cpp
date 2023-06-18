#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, x, y;

    void read_input() {
        ifstream fin("in");
        fin >> n >> x >> y;
        fin.close();
    }

    int get_value(int n, int x, int y) {
        // Calculati valoarea de pe pozitia (x, y) din matricea de dimensiune 2^n x 2^n

        // Cazul de baza.
        if (n == 1) {
            if (x == 1 && y == 1)
                return 1;
            if (x == 1 && y == 2)
                return 2;
            if (x == 2 && y == 1)
                return 3;
            if (x == 2 && y == 2)
                return 4;
        }

        int step = (int) pow(2, (2 * n - 2));
        int mid = (int) pow (2, (n - 1));

        if (x <= mid && y <= mid)
            return get_value(n - 1, x, y);
        if (x <= mid && y > mid)
            return step + get_value(n - 1, x, y - mid);
        if (x > mid && y <= mid)
            return 2 * step + get_value(n - 1, x - mid, y);
        if (x > mid && y > mid)
            return 3 * step + get_value(n - 1, x - mid, y - mid);

        return 0;
    }

    int get_result() {
        return get_value(n, x, y);
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
