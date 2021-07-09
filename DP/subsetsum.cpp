// 5               number of elements
// 2 3 7 8 10      array of elements
// 19              sum

#include <iostream>
#include <cstdlib>
#include <cstring>

typedef long long ll;

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int sum;
    cin >> sum;

    bool dp[n+1][sum+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j= 1; j <= sum; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
        }
    } 

    cout << dp[n][sum] << endl;
}