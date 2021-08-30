#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string> > graph;
        
        for (vector<string> &account: accounts) {
            string name = "";
            for (string val: account) {
                if (name == "") {
                    name = val;
                    continue;
                }
                if (graph.find(val) == graph.end()) {
                    graph.insert(make_pair(val, vector<string> ()));
                }
                graph[val].push_back(account[1]);
                if (graph.find(account[1]) == graph.end()) {
                    graph.insert(make_pair(account[1], vector<string> ()));
                }
                graph[account[1]].push_back(val);
                emailToName[val] = name;
            }
        }
        
        vector<vector<string> > ans;        
        unordered_set<string> seen;
        for (const pair<string, vector<string> > &v: graph) {
            if (!seen.count(v.first)) {
                seen.insert(v.first);
                stack<string> s;
                s.push(v.first);
                vector<string> comp;
                while (!s.empty()) {
                    string email = s.top();
                    s.pop();
                    comp.push_back(email);
                    for (string str: graph[email]) {
                        if (!seen.count(str)) {
                            seen.insert(str);
                            s.push(str);
                        }
                    }
                }
                sort(comp.begin(), comp.end());
                comp.insert(comp.begin(), emailToName[v.first]);
                ans.push_back(comp);
            }
        }
        return ans;
    }
};