#include <bits/stdc++.h>
using namespace std;

struct Result {
    int len; // rezultat pentru cerinta 1
    vector<int> subsequence; // rezultat pentru cerinta 2
};

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, m;
    vector<int> v;
    vector<int> w;

    void read_input() {
        ifstream fin("in");
        fin >> n >> m;

        v.push_back(-1); // adaugare element fictiv - indexare de la 1
        for (int i = 1, e; i <= n; i++) {
            fin >> e;
            v.push_back(e);
        }

        w.push_back(-1); // adaugare element fictiv - indexare de la 1
        for (int i = 1, e; i <= m; i++) {
            fin >> e;
            w.push_back(e);
        }

        fin.close();
    }

    Result get_result() {
        Result result;
        result.len = 0;

        // Aflati cel mai lung subsir comun intre v (de lungime n)
        // si w (de lungime m).
        // Se puncteaza separat urmatoarele 2 cerinte:
        // 2.1. Lungimea CMLSC. Rezultatul pentru cerinta aceasta se va pune in
        // ``result.len``.
        // 2.2. Reconstructia CMLSC. Se puncteaza orice subsir comun maximal valid.
        // Solutia pentru aceasta cerinta se va pune in ``result.subsequence``.

        vector<vector<int>> dp;
        dp.resize(v.size() + 1);

        for (int i = 0; i < v.size() + 1; i++) {
            dp[i].resize(w.size() + 1, 0);
        }

        for (int i = 1; i <= v.size(); i++) {
            for (int j = 1; j <= w.size(); j++) {
                if (v[i-1] == w[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        result.len = dp[v.size()][w.size()] - 1;

        int len = result.len;
        int i = v.size(), j = w.size();

        while (i > 0 && j > 0) {
            if (v[i-1] == w[j-1]) {
                result.subsequence.push_back(v[i-1]);
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            }
            else
                j--;
        }

        result.subsequence.pop_back();
        reverse(result.subsequence.begin(), result.subsequence.end());

        return result;
    }

    void print_output(Result result) {
        ofstream fout("out");
        fout << result.len << '\n';
        for (int x : result.subsequence) {
            fout << x << ' ';
        }
        fout << '\n';
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
