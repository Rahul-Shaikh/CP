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
    ll _sum = accumulate(arr, arr+n, 0);
    ll hsum = _sum/2;
    if (_sum%2) {
        cout << false << endl;
        return 0;
    }

    bool dp[n+1][hsum+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < hsum + 1; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][hsum];
}