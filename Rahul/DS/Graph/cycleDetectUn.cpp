#include <iostream>
#include <list>

using namespace std;

class Subset {
    public:
    int parent, rank;
};

class DisjSet {
    int n;
    Subset *subsets;

    public:
    DisjSet(int n) {
        this->n = n;
        subsets = new Subset[n];
        for (int i = 0; i < n; i++) {
            subsets[i].rank = 0;
            subsets[i].parent = i;
        }
    }

    ~DisjSet() {
        delete subsets;
    }

    int find(int i) {
        if (subsets[i].parent != i) {
            subsets[i].parent = find(subsets[i].parent);
        }
        return subsets[i].parent;
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (subsets[u].rank < subsets[v].rank) {
            subsets[u].parent = v;
        } else {
            subsets[v].parent = u;
            if (subsets[u].rank == subsets[v].rank) subsets[u].rank++;
        }
    }

};

class Edge {
public:
    int src, dest;
    Edge(int u=0, int v=0) {
        src = u;
        dest = v;
    }
};

class Graph {
    int V;
    list<Edge> edges;
public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v) {
        edges.emplace_back(u, v);
    }

    bool isCycle() {
        DisjSet disj(V);
        for (int i = 0; i < edges.size(); i++) {
            Edge e = *next(edges.begin(), i);
            int x = e.src;
            int y = e.dest;
            int xset = disj.find(x);
            int yset = disj.find(y);

            if (xset == yset) return true;

            disj.join(xset, yset);
        }
        return false;
    }
};



int main(void) {
    int v, e;
    v = 3, e = 3;

    Graph g(3);
    
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    // g.addEdge(0, 2);

    if (g.isCycle()) {
        cout << "Cycle detected\n";
    } else {
        cout << "No Cycle\n";
    }
}