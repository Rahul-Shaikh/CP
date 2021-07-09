#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long ll;

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[n];
    int val;
    cin >> val;

    int dp[n+1][val+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n+1; i++) dp[i][0] = 1;

    for (int i = 1; i < n+1 ; i++) {
        for (int j = 1; j < val+1; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][val];
}