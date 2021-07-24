#include <iostream>
#include <cstring>

using namespace std;

int lps(string s) {
    int n = s.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int l = 2; l <= n; l++) {
        for (int st = 0; st < n - l + 1; st++) {
            int en = st + l - 1;
            if (s[st] == s[en] && l == 2) dp[st][en] = 2;
            else if (s[st] == s[en]) dp[st][en] = 2 + dp[st+1][en-1];
            else dp[st][en] = max(dp[st][en-1], dp[st+1][en]);
        }
    }
    return dp[0][n-1];
}

int main(void) {
    string s;
    cin >> s;

    int x = lps(s);
    cout << s.size() - x << endl;
}