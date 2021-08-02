#include <iostream>
#include <climits>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int V;
    list<pair<int, int> > *adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new list<pair<int, int> >[V];
    }

    void addEdge(int u, int v, int val) {
        adj[u].push_back(make_pair(v, val));
    }


    vector<int> dijkstra(int s) {
        vector<int> dist(V, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        pq.push(make_pair(0, s));
        dist[s] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;

            pq.pop();
            for (pair<int, int> p: adj[u]) {
                int w = p.first;
                int v = p.second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = w + dist[u];
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        for (int i = 0; i < V; i++) {
            cout << i << "\t" << dist[i] <<endl;
        }
    }
};

int main(void) {
    
}