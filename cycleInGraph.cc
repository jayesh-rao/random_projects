#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int n;
    vector< vector<int> > adj;
public:
    Graph(int n) : n(n) {
        for (int i = 0; i < n; i++) {
            adj.push_back(vector<int>());
        }
    }
    void add_edge(int i, int j) {
        // For vertex i, add an edge joining 'j'
        adj[i].push_back(j);
    }

    void dfs(int start, vector<bool>& visited) {
        if (visited[start]) return;
        visited[start] = true;
        cout << endl << start;
        for (auto &e: adj[start]) {
            dfs(e, visited);
        }
    }
};

int main() {

    Graph *g = new Graph(5);
    vector<bool> visited = {false, false, false, false, false};
    g->add_edge(0, 4);
    g->add_edge(0, 3);
    g->add_edge(1, 3);
    g->add_edge(3, 4);
    for (int i = 0; i < 5; i++) {
        g->dfs(0, visited);
    }
    cout << endl;
}
