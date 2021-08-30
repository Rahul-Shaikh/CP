#include <iostream>

using namespace std;

int solve(int n, int k) {
    if (n==1) return 1;
    return (k - 1 + solve(n-1, k))%n + 1;
}
int solve2(int n, int k) {
    if (n==1) return 1;
    int val = (k + solve(n-1, k)) % (n); 
    return val ? val : n;
}

int main(void) {
    int n, k;
    cin >> n >> k;

    cout << solve(n, k) << endl;
    cout << solve2(n, k) << endl;
}