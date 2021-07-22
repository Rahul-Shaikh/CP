#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    int n = s.size();
    int dp[n][n];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) dp[i][i] = 1;
    int mx = 1;
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1] ) {
            dp[i][i+1] = 2;
            mx = 2;
        } else dp[i][i+1] =1;
    }

    for (int l = 3; l <= n; l++) {
        for (int st = 0; st < n-l+1; st++) {
            int en = st + l -1;
            if (s[st] == s[en]){
             dp[st][en] = 2 + dp[st+1][en-1]; 
            //  mx = max(dp[st][en], mx);
        }
            else dp[st][en] = max(dp[st+1][en], dp[st][en-1]);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "max len: " << dp[0][n-1];
}