#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>

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

void DFS(int src, Graph &g, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<pair<int, int> > &ans) {
    static int t = 0;
    disc[src] = low[src] = t;
    t++;

    for (int v: g.adj[src]) {
        if (disc[v] == -1) {
            parent[v] = src;
            DFS(v, g, disc, low, parent, ans);
            low[src] = min(low[v], low[src]);

            if (low[v] > disc[src]) {
                ans.push_back({src, v});
            }
        } else if (v != parent[src]) {
            low[src] = min(low[src], disc[v]);
        }
    }
}

vector<pair<int, int> > findBridges(Graph &g) {
    int V = g.V;
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    vector<pair<int, int> > ans;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            DFS(i, g, disc, low, parent, ans);
        }
    }

    return ans;
}

int main(void) {
    Graph g(5);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1, 0);
    g.addEdge(2,1);
    g.addEdge(3, 4);

    vector<pair<int, int> > ans = findBridges(g);

    cout << "Bridges are: " << endl;
    for (auto val: ans) {
        cout << val.first << " " << val.second << endl;
    }
}