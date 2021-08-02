#include <iostream>
#include <list>
#include <cstring>
#include <queue>

using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool isCyclicUtil(int u, bool* visited, bool *recurStack) {
        if (!visited[u]) {
            visited[u] = true;
            recurStack[u] = true;
            for (int v: adj[u]) {
                
                if (!visited[v] && isCyclicUtil(v, visited, recurStack)) return true;
                if (recurStack[v]) return true;
            }
            recurStack[u] = false;
            return false;
        }
    }

    bool isCyclic() {
        bool visited[V];
        memset(visited, 0 ,sizeof(visited));
        bool recurStack[V];
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < V; i++) {
            if (isCyclicUtil(i, visited, recurStack)) return true;
        }
        return false;
    }
};

int main(void) {
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}