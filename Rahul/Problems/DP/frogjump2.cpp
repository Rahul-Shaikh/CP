#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;
typedef vector<int> vi;

bool canCross(vi &stones) {
    if (stones.size() <= 1) return true;
    if (stones[0] != 0) return false;
    if (stones[1] != 1) return false;

    int n = stones.size();
    unordered_map<int, vi> um;
    for (int i = 0; i < n; i++) {
        um.insert(make_pair(stones[i], vector<int>()));
    }
    um[1].push_back(1);

    for (int i = 1; i < n; i++) {
        for (int jump: um[stones[i]]) {
            for (int j = jump-1; j <= jump+1; j++) {
                if (j > 0) {
                    if (um.count(j + stones[i])) {
                        um[stones[i] + j].push_back(j);
                    }
                }
            }
        }
    }

    return um[stones.back()].size() != 0;
}

int main(void) {
    
}