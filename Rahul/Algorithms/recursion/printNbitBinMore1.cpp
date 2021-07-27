#include <iostream>

using namespace std;

void solve(int n, int one, int zero, string ans) {
    if (n == 0) {
        cout << ans << endl;
        return;
    }

    solve(n-1, one +1, zero, ans+"1");
    if (one > zero) solve(n-1, one, zero+1, ans+"0"); 
}

int main(void) {
    int n;
    cin >> n;

    solve(n, 0, 0, "");
}