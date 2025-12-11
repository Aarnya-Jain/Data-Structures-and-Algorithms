#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class graph {
public:
    vector<vector<T>> mat;

    graph(int n, T defaultValue = 0) {
        mat.resize(n, vector<T>(n, defaultValue));
    }

    void addEdge(int u, int v, bool direction) {
        // direction = 0 --> undirected
        // direction = 1 --> directed
        mat[u][v] = 1;

        if (!direction) {
            mat[v][u] = 1;
        }
    }

    void printMatrix() {
        cout << "\n---- Adjacency Matrix ----\n";
        for (auto &row : mat) {
            for (auto &val : row) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    graph<int> g(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;

        g.addEdge(u, v, 0);  // making an undirected graph
    }

    g.printMatrix();

    return 0;
}