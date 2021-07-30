#include <iostream>
#include <climits>
#include <list>
#include <vector>

using namespace std;

class Edge {
    public:
    int src, dest, weight;
    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        weight = w;
    }
};

class Graph {
    int V;
    // int E;
    list<Edge> edges;

    public:

    Graph(int V) {
        this->V = V;
        // this->E = E;
        // edges = new Edge[E];
    }

    void addEge(int u, int v, int w) {
        edges.push_back(Edge(u,v,w));
    }

    vector<int> bellmanford(int s) {
        vector<int> dist(V, INT_MAX);

        dist[s] = 0;
        for (int  i = 0; i < V-1;i++) {
            // cout << "in loop\n";
            for (Edge e: edges) {
                int v = e.dest;
                int u = e.src;
                int w = e.weight;
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;

                }
            }
        }
        for (Edge e: edges) {
            int v = e.dest;
            int u = e.src;
            int w = e.weight;
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                cout << "Negative cycle deteced\n";
                return vector<int> ();
            }
        }

        for (int i = 0; i < V; i++) {
            cout << i << "\t" << dist[i] <<endl;
        }

        return dist;
    }
};

int main(void) {
    Graph g(5);

    g.addEge(0,1,-1);
    g.addEge(0, 2 ,4);
    g.addEge(1,2,3);
    g.addEge(1,3,2);
    g.addEge(1,4,2);
    g.addEge(3,2,5);
    g.addEge(3,1,1);
    g.addEge(4,3,-20);

    g.bellmanford(0);
}