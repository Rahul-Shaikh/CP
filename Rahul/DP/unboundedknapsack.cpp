// rod cutting same

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long ll;

int main(void) {
    int n;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++) cin >> w[i];
    int v[n];
    for (int i = 0; i < n; i++) cin >> v[i];
    int total;
    cin >> total;

    int dp[n+1][total+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= total; j++) {
            if (w[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i][j-v[i-1]]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][total] << endl;
    return 0;
}