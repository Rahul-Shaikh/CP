#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <list>

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

    void kahnsAlgo() {
        vector<int> topological_order;

        queue<int> q;

        int indegree[V];
        memset(indegree, 0, sizeof(indegree));

        for (int i = 0; i < V; i++) {
            for (int v: adj[i]) {
                indegree[v]++;
            }
        }

        for (int i = 0; i < V; i++) {
            if (!indegree[i]) q.push(i);
        }

        if (q.size() == 0) {
            cout << "Not possible\n";
            return;
        }

        int cnt = 0;
        while (!q.empty()) {
            cnt++;
            int u = q.front();
            q.pop();
            topological_order.push_back(u);

            for (int v: adj[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }

        if (cnt != V) {
            cout << "Not possible\n";
            return;
        }

        for (int i = 0; i < V; i++) {
            cout << topological_order[i] << " ";
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
 
    cout << "Following is a Topological Sort of\n";
    g.kahnsAlgo();
 
}