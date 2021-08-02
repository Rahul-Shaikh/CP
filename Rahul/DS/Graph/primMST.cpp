#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Graph
{
    int V;
    list<pair<int, int> > *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int> >[V];
    }

    void addEdge(int u, int v, int val)
    {
        adj[u].push_back(make_pair(v, val));
        adj[v].push_back(make_pair(u, val));
    }

    void primMST()
    {
        priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;

        int src = 0; 

        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        pq.push(make_pair(0, src));
        key[src] = 0;

        /* Looping till priority queue becomes empty */
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u] == true)
            {
                continue;
            }

            inMST[u] = true; 

            list<pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i).first;
                int weight = (*i).second;

                if (inMST[v] == false)
                {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        for (int i = 1; i < V; ++i)
            printf("%d - %d\n", parent[i], i);
    }
};

int main(void)
{
    Graph g(9);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.primMST();
}
