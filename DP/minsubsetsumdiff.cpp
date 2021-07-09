// 4            number of elements
// 2 8 15 8     array of elements

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

    int sum = accumulate(arr, arr+n, 0);
    int hsum = sum/2;
    bool dp[n+1][hsum+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n+1; i++) dp[i][0] = true;

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < hsum+1; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    for (int i = hsum; i >= 0; i--) {
        if (dp[n][i]) {
            cout << sum-2*i << endl;
            return 0;
        }
    }

    return 0;
}