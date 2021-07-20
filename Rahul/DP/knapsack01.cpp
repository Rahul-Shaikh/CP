// input:
// 4        number of elements
// 7        total weight
// 1 3 4 5  weight array
// 1 4 5 7  value array

#include <iostream>
#include <cstdlib>
#include <cstring>

typedef long long ll;
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int tw;
    cin >> tw;
    int weight[n];
    int value[n];
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) cin >> value[i];
    
    ll dp[n+1][tw+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++ ) {
        for (int j = 1; j <= tw; j++) {
            if (weight[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i-1][j-weight[i-1]]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][tw];
    
    return 0;
}