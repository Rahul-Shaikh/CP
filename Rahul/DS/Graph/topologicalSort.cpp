#include <iostream>
#include <stack>
#include <cstring>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int v) {
        V = v;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topologicalSortUtil(int u, bool *visited, stack<int> &s) {
        visited[u] = true;
        for (int v: adj[u]) {
            if (!visited[v]) {
                topologicalSortUtil(v, visited, s);
            }
        }

        s.push(u);
    }

    void topologicalSort() {
        stack<int> s;
        bool visited[V];
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, s);
            }
        }

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main(void) {
      Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.topologicalSort();
 
    return 0;
}