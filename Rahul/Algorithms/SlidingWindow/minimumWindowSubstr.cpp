#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

void printhash(unordered_map<char, int> hash) {
    cout << "====================" << endl;
    for (auto v: hash) {
        cout << v.first << " ----> " << v.second <<endl;
    }
    cout << endl;
}
string minWindow(string s, string t) {
    unordered_map<char, int> um;
    
    for (char c: t) um[c]++;
    int formed = 0;
    int idx = -1;
    int len = INT_MAX;
    int i = 0, j = 0;
    while (j < s.size()) {
        if (um.count(s[j])) {
            if (um[s[j]] == 1) {
                formed++;
            }
            um[s[j]]--;
        }
        
        if (formed < um.size()) {
            j++;
        } else if (formed == um.size()) {
            
            do {
                // cout << i << " " << j << endl;
                if (j-i+1 < len) {
                    len = j-i+1;
                    idx = i;
                }
                if (um.count(s[i])) {
                    if (um[s[i]] == 0) {
                        formed--;
                    }
                    um[s[i]]++;
                }
                i++;
            } while (i <= j && formed == um.size());
            j++;
        }
        
    }
    return idx != -1 ? s.substr(idx, len) : "";
}
int main(void) {
    string str, ptn;
    cin >> str >> ptn;

    int i = 0, j = 0;
    unordered_map<char, int> hash;
    int idx = -1, len = INT_MAX;
    for (int i = 0 ; i < ptn.size(); i++) hash[ptn[i]]++;
    int count = hash.size();
    bool flag = 0;
    while (j < str.size()) {
        // cout << i << " "<< j << endl;
        if (hash.find(str[j]) != hash.end()) {
            hash[str[j]]--;
            if (hash[str[j]] < 0) {
                flag = 1;
            }
            else if (hash[str[j]] == 0) count--;
        }
        
        if (count == 0 && !flag) {
            while (hash.find(str[i]) == hash.end()) {
                i++;
            }
            if (len > j-i+1) {
                len = j-i+1;
                idx = i;
            }
            j++;
        }
        else if (count > 0 && !flag) {
            j++;
        }
        
        if (flag) {
            while (hash[str[j]] < 0) {
                // cout << i << " "<< j << endl;
                if (hash.find(str[i]) != hash.end()) {
                    if (hash[str[i]] == 0) count++;
                    hash[str[i]]++;
                }
                i++;
                // printhash(hash);
                // cout << count << endl;
            }
            flag = 0;
            j++;
        }
        // printhash(hash);
        // cout << count << endl;
    }
    if (idx != -1) cout << str.substr(idx, len);
    else cout << "not present\n";
}