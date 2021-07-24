#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int dp[s1.size()+1][s2.size()+1];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << "length of lcs: "<< dp[s1.size()][s2.size()];
}