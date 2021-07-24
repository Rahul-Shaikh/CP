#include <iostream>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

bool isPalin(string s) {
    if (s.size() <= 1) return true;

    int hi = s.size() - 1, lo = 0;
    while (lo < hi) {
        if (s[hi] != s[lo]) return false;
        lo++, hi--;
    }
    return true;
}

int solve(string s, unordered_map<string, int> &hash) {
    // cout << s << endl;
    if (isPalin(s)) return 0;

    if (hash.find(s) != hash.end()) return hash[s];

    int n = s.size();
    int mn = INT_MAX;
    for (int i = 0; i <= n-2; i++) {
        int  temp = 1+solve(s.substr(0, i+1), hash) + solve(s.substr(i+1), hash);
        // cout <<  " temp " << temp << endl;
        mn = min(temp, mn);
        // cout << "min " << mn << endl;
    }
    hash.insert(make_pair(s, mn));
    return mn;
}

int main(void) {
    unordered_map<string, int> hash;

    string s;
    cin >> s;

    cout << solve(s, hash) << endl;
}