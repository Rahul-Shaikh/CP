#include <iostream>

using namespace std;

int solve(int n, int k) {
    if (n==1) return 1;
    return (k - 1 + solve(n-1, k))%n + 1;
}

int main(void) {
    int n, k;
    cin >> n >> k;

    cout << solve(n, k) << endl;
}