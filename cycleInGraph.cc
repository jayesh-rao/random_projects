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

    bool dfs(int start, vector<bool>& visited) {
        if (visited[start]) return true;
        visited[start] = true;
        cout << endl << start;
        bool ret = false;
        for (auto &e: adj[start]) {
            ret |= dfs(e, visited);
        }
        return ret;
    }
};

int main() {

    Graph *g = new Graph(5);
    vector<bool> visited = {false, false, false, false, false};
    g->add_edge(0, 4);
    g->add_edge(0, 3);
    g->add_edge(1, 3);
    g->add_edge(0, 1);
    //for (int i = 0; i < 5; i++) {
        if (g->dfs(0, visited))
            cout << "\n is cyclic";
        else
            cout << "\n is not cyclic";
    //}
    cout << endl;
}
