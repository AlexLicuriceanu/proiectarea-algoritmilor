#include <iostream>
#include <fstream>
#include <vector>


#include "./shortest_path.h"

using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(compute());
    }

private:
    // n = numar de noduri, m = numar de muchii
    int n, m;
    // adj[i] = lista de adiacenta a nodului i
    // perechea (j, w) semnifica muchie de la i la j de cost w
    vector<pair<int, int>> adj[NMAX];

    void read_input() {
        ifstream fin("in");
        fin >> n >> m;
        for (int i = 1, x, y, w; i <= m; i++) {
            fin >> x >> y >> w;
            adj[x].push_back({y, w});
        }
        fin.close();
    }

    void reweight() {
        for (int i = 1; i <= n; i++) {
            adj[0].push_back({i, 0});
        }
    }

    vector<Edge>& constructEdges() {
        vector<Edge> edges;
        for (int i = 1; i <= n; i++) {
            for (const auto& [neigh, w] : adj[i]) {
                edges.push_back(Edge(i, neigh, w));
            }
        }
        return edges;
    }

    JohnsonResult compute() {
        //
        // Gasiti distantele minime intre oricare doua noduri, folosind
        // algoritmul lui Johnson pe graful orientat cu n noduri, m arce stocat in adk.
        //
        // Atentie:
        // O muchie este tinuta ca o pereche (nod adiacent, cost muchie):
        //     adj[node][i] == (neigh, w) - unde neigh este al i-lea vecin al lui node, iar (node, neigh) are cost w.
        //
        //
        // Trebuie sa întoarceți o structură de tipul JohnsonResult, care contine membrii
        //  * has_cycle = true, dacă a fost întâlnit un ciclu de cost negativ
        //  * d = matricea de distante, unde se setează d[u][v] = 0, daca nu a fost gasit
        // un drum de la u la v. d[u][u] = 0
        //  * p = matricea de parinti, unde p[u][v] = parintele nodului v, pornind din nodul u.
        // si p[u][v] = 0, daca v nu se poate atinge din nodul u
        //
        // Verificati "shortest_path.h":
        // * Structuri ajutatoare: Edge, JohnsonResult.
        // * Implementare data Dijkstra, BellmanFord.
        //

        reweight();

        // Step 2: Run Bellman-Ford to compute potentials (h values)
        BellmanFordResult bellmanResult = bellman(0, n, constructEdges());

        // Check if a negative cycle was detected in the graph
        if (bellmanResult.has_cycle) {
            return {true, {}, {}};
        }

        // Step 3: Create a new graph with modified edge weights
        vector<pair<int, int>> modifiedAdj[NMAX];
        for (int i = 1; i <= n; i++) {
            for (const auto& [neigh, w] : adj[i]) {
                int modifiedWeight = w + bellmanResult.d[i] - bellmanResult.d[neigh];
                modifiedAdj[i].push_back({neigh, modifiedWeight});
            }
        }

        // Step 4: Run Dijkstra's algorithm for each node to find shortest paths
        vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> p(n + 1, vector<int>(n + 1, 0));

        for (int u = 1; u <= n; u++) {
            DijkstraResult dijkstraResult = dijkstra(u, n, modifiedAdj);

            // Store the distances and paths in the result matrices
            for (int v = 1; v <= n; v++) {
                d[u][v] = dijkstraResult.d[v];
                p[u][v] = dijkstraResult.p[v];
            }
        }

        // Step 5: Restore distances by subtracting the potentials
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (d[u][v] != INF) {
                    d[u][v] -= bellmanResult.d[u] - bellmanResult.d[v];
                }
            }
        }

        return {false, d, p};
    }

    void print_output(const JohnsonResult &res) {
        ofstream fout("out");
        if (res.has_cycle) {
            fout << "Ciclu negativ!\n";
            return;
        }

        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                fout << res.d[u][v] << ' ';
            }
            fout << '\n';
        }
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
