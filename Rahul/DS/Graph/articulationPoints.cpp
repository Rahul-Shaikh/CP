#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    public:
    int V;
    list<int> *adj;
    Graph(int V) {
        this->V = V;
        adj = new list<int> [V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

void dfs(Graph &g, int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &isAP) {
    static int t = 0;
    disc[u] = low[u] = t;
    t++;
    int child = 0;

    for (int v: g.adj[u]) {
        if (disc[v] == -1) {
            child++;
            parent[v] = u;
            dfs(g, v, disc, low, parent, isAP);
            low[u] = min(low[u], low[v]);

            if ((parent[u] == -1 && child > 1) || (parent[u] != -1 && disc[u] <= low[v])) {
                isAP[u] = true;
            }
        } else if (parent[v] != u) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

vector<int> findAP(Graph &g) {
    int V = g.V;
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    vector<bool> isAP(V, false);

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            dfs(g, i, disc, low, parent, isAP);
        }
    }
    vector<int> aps;
    for (int i = 0; i < V; i++) {
        if (isAP[i]) {
            aps.push_back(i);
        }
    }

    return aps;
}

int main(void) {
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1, 0);
    g.addEdge(2,1);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    vector<int> aps = findAP(g);
    for (int ap: aps) {
        cout << ap << " ";
    }
    cout << endl;
}