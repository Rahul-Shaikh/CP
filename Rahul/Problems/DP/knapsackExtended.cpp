// Problem
// Dr. Patel has N stacks of plates. Each stack contains K plates. Each plate has a positive beauty value, describing how beautiful it looks.

// Dr. Patel would like to take exactly P plates to use for dinner tonight. If he would like to take a plate in a stack, he must also take all of the plates above it in that stack as well.

// Help Dr. Patel pick the P plates that would maximize the total sum of beauty values.

// Input
// The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the three integers N, K and P. Then, N lines follow. The i-th line contains K integers, describing the beauty values of each stack of plates from top to bottom.

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    int t = 0;
    while (t++ < T) {
        int n, k, p;
        
        cin >> n >> k >> p;
        vector<vector<int> > arr(n, vector<int> (k,0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cin >> arr[i][j];
            }
        }
        int sum[n+1][k+1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (i ==0 || j == 0) {
                    sum[i][j] = 0;
                }
                else {
                    sum[i][j] = sum[i][j-1] + arr[i-1][j-1];
                }
            }
        }
        
        int dp[n+1][p+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= p; j ++) {
                for (int x = 0; x <= min(j, k); x++) {
                    dp[i][j] = max(dp[i][j], sum[i][x] + dp[i-1][j-x]);
                }
            }
        }
        cout << "Case #" << t << ": " << dp[n][p] << endl;
    }
} 