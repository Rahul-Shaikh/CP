#include <iostream>
#include <cstring>
#include <climits>

using namespace std; // max array 10^7 * 6 (can be 10^8 global and for safety 10^6 local)
typedef long long ll;


ll memo[1001][1001];


ll solve(int* arr, int i, int j) {
    if (i == j) return 0;

    if (memo[i][j] != -1) return memo[i][j];
    ll mn = INT_MAX;
    for (int k = i; k < j; k++) {
        ll temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        mn = min(mn, temp);
    }

    return memo[i][j] = mn;
}

int main(void) {
    memset(memo, -1, sizeof(memo));
    // cout << "coming here\n";
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i ++ ) cin >> arr[i];
    for (int i = 0; i < n; i ++ ) cout <<  arr[i] << " ";
    cout << endl;

    cout << solve(arr, 1, n-1) << endl;    
}