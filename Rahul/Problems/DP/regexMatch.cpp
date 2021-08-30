#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool solveUtil(string s, string p, int sidx, int pidx) {
    int ans = 0;
    if (pidx == p.size()) {
        if (sidx == s.size()) ans = 1;
        else ans = 0;
    } else {
        int first_match = (sidx < s.size() && (s[sidx] == p[pidx] || p[pidx] == '.')) ? 1 : 0;

        if (pidx + 1< p.size() && p[pidx] == '*') {
            ans = solveUtil(s, p, sidx, pidx+2);
            if (!ans && first_match) ans = solveUtil(s, p, sidx + 1, pidx);
        } else {
            if (first_match) ans = solveUtil(s, p, sidx + 1, pidx + 1);
            else ans = 0;
        }
    }

    return ans;
}

bool solve(string s, string p) {
    if (s=="" && p == "") return true;

    return solveUtil(s, p, 0, 0);
}

int main(void) {
    string s, p;
    cin >> s >> p;
    cout << solve(s, p);
}