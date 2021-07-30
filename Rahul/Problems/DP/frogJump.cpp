#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<int, int> us;

unordered_map<string, bool > um;
bool solve(vector<int> &stones, int i, int k) {
    if (i == stones.size()-1) return true;
    if (i > stones.size()) return false;
    if (k == 0) return false;
    
    
    cout << i << " " << k << endl;
    
    string key = to_string(i);
    key += "_";
    key += to_string(k);
    
    if (um.find(key) != um.end()) return um[key];
    
    if (us.find(stones[i] + k-1) != us.end()) {
        // cout << "here1" <<endl;
        if (solve(stones, us[stones[i] + k-1], k-1)) return um[key] = true;
    }
    
    if (us.find(stones[i] + k) != us.end()) {
        // cout << "here2" << endl;
        if (solve(stones, us[stones[i] + k], k)) return um[key] = true;
    }
    
    if (us.find(stones[i] + k+1) != us.end()) {
        // cout << "here3" <<endl;
        if (solve(stones, us[stones[i] + k+1], k+1)) return um[key] = true;
    }
    
    return um[key] = false;
}

bool canCross(vector<int>& stones) {
    if (stones.size() <= 1) return true;
    if (stones[0] != 0) return false;
    if (stones[1] != 1) return false;
    for (int i = 0; i < stones.size(); i++) us.insert(make_pair(stones[i], i));
    return solve(stones, 1, 1);
}