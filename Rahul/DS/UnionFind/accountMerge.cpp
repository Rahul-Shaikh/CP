#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class DSU {
    vector<int> parent;
    vector<int> rank;
    
    public:
    DSU() {
        parent.resize(10001);
        rank.resize(10001);
        for (int i = 0; i <= 10000; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
    void join(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot == yroot) return;
        if (rank[xroot] > rank[yroot]) {
            parent[yroot] = xroot;
        } else if (rank[yroot] > rank[xroot]) {
            parent[xroot] = yroot;
        } else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU disj;
        unordered_map<string, string> emailToName;
        unordered_map<string, int> emailToID;
        
        int id = 0;
        for (const vector<string> &account: accounts) {
            string name = "";
            for (const string &val: account) {
                if (name == "") {
                    name = val;
                    continue;
                }
                if (emailToID.find(account[1]) == emailToID.end()) {
                    emailToID[account[1]] = id++;
                }
                if (emailToID.find(val) == emailToID.end()) {
                    emailToID[val] = id++;
                }
                emailToName[val] = name;
                // if (account[1] == val) continue;
                disj.join(emailToID[val], emailToID[account[1]]);
            }
        }
        
        unordered_map<int, vector<string> > res;
        for (const pair<string, string> &p: emailToName) {
            int idx = disj.find(emailToID[p.first]);
            if (res.find(idx) == res.end()) {
                res.insert(make_pair(idx, vector<string> ()));
            }
            res[idx].push_back(p.first);
        }
        vector<vector<string> > ans;
        for (pair<int, vector<string> > p: res) {
            sort(p.second.begin(), p.second.end());
            p.second.insert(p.second.begin(), emailToName[p.second[0]]);
            ans.push_back(p.second);
        }
        return ans;
    }
};