// 6                number of elements
// 2 8 10 7 3 5     array of elements
// 10               sum

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long ll;

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int sum;
    cin >> sum;

    int dp[n+1][sum+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < sum+1; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][sum] << endl;
}