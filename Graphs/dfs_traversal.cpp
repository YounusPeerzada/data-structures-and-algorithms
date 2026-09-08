#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
   int V;
   list<int> *l;

   public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge (int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int src, vector<bool> &visited) {
        cout << src << " ";
        visited[src] = true;

        for (int neigh : l[src]) {
            if (!visited[neigh]) {
                dfsHelper(neigh, visited);
            }
        }
    }

    void dfs () {
        int src = 0;
        vector<bool> visited(V, false);

        dfsHelper(src, visited);
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "dfs traversal : ";

    g.dfs();
}