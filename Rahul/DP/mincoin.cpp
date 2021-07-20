#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;
typedef long long ll;

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int val;
    cin >> val;

    int dp[n+1][val+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < val+1; i++) dp[0][i] = INT_MAX - 1;

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < val+1; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-arr[i-1]]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][val];
}