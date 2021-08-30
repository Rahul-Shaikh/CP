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

void DFS(int src, Graph &g, vector<int> &disc, vector<int> &low, vector<vector<int> > &ans, stack<int> &s, vector<bool> &inStack) {
    static int t = 0;
    disc[src] = low[src] = t;
    t++;
    inStack[src] = true;
    s.push(src);

    for (int v: g.adj[src]) {
        if (disc[v] == -1) {
            DFS(v, g, disc, low, ans, s, inStack);
            low[src] = min(low[v], low[src]);
        }
        else if (inStack[v]) {
            low[src] = min(low[src], disc[v]);
        }
    }

    if (low[src] == disc[src]) {
        vector<int> temp;
        while (!s.empty() && s.top() != src) {
            temp.push_back(s.top());
            inStack[s.top()] = false;
            s.pop();
        }
        temp.push_back(s.top());
        inStack[s.top()] = false;
        s.pop();
        ans.push_back(temp);
    }
}

vector<vector<int> > findSCC(Graph &g) {
    int V = g.V;
    vector<int> disc(V, -1), low(V, -1);
    vector<vector<int> > ans;
    vector<bool> inStack(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            DFS(i, g, disc, low, ans, s, inStack);
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

    vector<vector<int> > ans = findSCC(g);

    
}