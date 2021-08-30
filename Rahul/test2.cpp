#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <climits>

using namespace std;

vector<bool> visited;

class Graph {
    int V;
    public:
    list<int> *adj;
    Graph(int V) {
        this->V = V+1;
        adj = new list<int>[V+1];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

int dfs(int u, Graph &g) {
    // cnt++;
    int cnt = 0;
    for (int v: g.adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            cnt += dfs(v, g);
        }
    }
    return ++cnt;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    Graph g(n+1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int mn = INT_MAX;
    visited = vector<bool> (n+1, false);
    for (int i = 1; i <=n; i++) {
        if (!visited[i]) {
            // int cnt = 0;
            visited[i] = true;
            
            mn = min(dfs(i, g), mn);
        }
    }
    cout << mn << endl;
}