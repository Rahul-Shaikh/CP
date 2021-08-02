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
    int src, dest, weight;
    Edge(int u=0, int v=0, int w=0) {
        src = u;
        dest = v;
        weight = w;
    }
};

bool cmp(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

class Graph {
    int V;
    list<Edge> edges;
public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int w) {
        edges.emplace_back(u, v, w);
    }

    void kruskalMST() {
        DisjSet disj(V);

        int i = 0;
        int e = 0;

        edges.sort(cmp);
        Edge result[V];

        while (e < V-1 && i < edges.size()) {
            Edge next_edge = *next(edges.begin(), i);
            i++;

            int u = next_edge.src;
            int v = next_edge.dest;
            int w = next_edge.weight;

            int uset = disj.find(u);
            int vset = disj.find(v);

            cout << u << " " << uset << endl;
            cout << v << " " << vset << endl;
            if (uset != vset) {
                result[e++] = next_edge;
                disj.join(u, v);
                uset = disj.find(u);
                vset = disj.find(v);
                cout << u << " " << uset << endl;
                cout << v << " " << vset << endl;
            }
            cout << "-----------\n";
        }

        int minCost = 0;
        for (int i = 0; i < e; i++) {
            cout << result[i].src << " ----------- " << result[i].dest << " = " <<  result[i].weight << endl;
            minCost += result[i].weight; 
        }
        cout << "Minimum Cost: " << minCost << endl; 
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

    Graph g(4);
    
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    // if (g.isCycle()) {
    //     cout << "Cycle detected\n";
    // } else {
    //     cout << "No Cycle\n";
    // }

    g.kruskalMST();
}