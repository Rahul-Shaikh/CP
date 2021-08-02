#include <iostream>

using namespace std;

class Subset {
public:
    int parent;
    int rank;
};

class DisjSet {
    int n;
    Subset *subsets;

public:
    DisjSet(int n) {
        this->n = n;
        subsets = new Subset[n];
        for (int i = 0; i < n; i++) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }
    }

    int find(int u) {
        if (subsets[u].parent != u) {
            subsets[u].parent = find(subsets[u].parent);
        }
        return subsets[u].parent;
    }

    bool inSameSubset(int u, int v) {
        int x = find(u);
        int y = find(v);

        return x==y;
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

    ~DisjSet() {
        delete subsets;
    }
};

int main(void) {
    
}