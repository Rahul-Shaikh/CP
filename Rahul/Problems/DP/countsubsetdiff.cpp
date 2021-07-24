#include <iostream>
#include <cstring>
#include <cstdlib>
#include <numeric>
using namespace std;
typedef long long ll;

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int diff;
    cin >> diff;

    int sum = accumulate(arr, arr+n, 0);
    int mysum = (sum + diff)/2;
    if (mysum*2 != (sum + diff)) {
        cout << false << endl;
        return 0;
    }

    int dp[n+1][mysum+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n+1; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= mysum; j++) {
            if (arr[i-1] <= j) dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][mysum];
    return 0;
}