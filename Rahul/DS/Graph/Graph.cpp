#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
    bool isDirected;

    void dfsRecurUtil(int s, vector<bool> &vis) {
        cout << s << " ";
        vis[s] = true;
        
        for (int v: adj[s]) {
            if (!vis[v]) {
                dfsRecurUtil(v, vis);
            }
        }

    }
public:
    Graph(int V, bool isDirected=true) {
        this->V = V;
        adj = new list<int>[V];
        this->isDirected = isDirected;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if (!isDirected) adj[v].push_back(u);
    }

    void bfs(int s) {
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(s);
        visited[s] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v: adj[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << endl;
    }

    void dfs(int s) {
        stack<int> stk;
        vector<bool> visited(V,false);

        stk.push(s);
        visited[s] = true;

        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();
            cout << u << " ";
            for (int v: adj[u]) {
                if (!visited[v]) {
                    stk.push(v);
                    visited[v] = true;
                }
            }
        }

        cout << endl;
    }

    void dfsRecur(int s) {
        vector<bool> visited(V, false);
        dfsRecurUtil(s, visited);
        cout << endl;
    }
};

int main(void) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
    g.bfs(2);
    g.dfs(1);
    g.dfsRecur(2);
}