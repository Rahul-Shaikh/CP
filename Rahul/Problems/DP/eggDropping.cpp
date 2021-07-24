#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int memo[1001][1001];

int solve(int e, int f) {
    if (e == 1) return f;
    if (f <= 1) return f;

    if (memo[e][f] != -1) return memo[e][f];

    int mn = INT_MAX;
    for (int i = 1; i <= f; i++) {
        int temp = 1 + max(solve(e,f-i), solve(e-1, i-1));
        mn = min(mn, temp);
    }

    return memo[e][f] = mn;
}

int main() {
    memset(memo, -1, sizeof(memo));

    int e, f;
    cin >> e >> f;

    cout << solve(e, f) << endl;
}