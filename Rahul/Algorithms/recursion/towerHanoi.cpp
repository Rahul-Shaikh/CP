#include <iostream>

using namespace std;

void solve(int n, char s, char d, char h) {
    if (n == 1) {
        cout << "Move " << n << " from " << s << " to " << d << endl;
        return; 
    }
    solve(n - 1, s, h, d);
    cout << "Move " << n << " from " << s << " to " << d << endl;
    solve(n - 1, h, d, s);
}

int main(void) {
    int n;
    cin >> n;

    solve(n, 'A', 'C', 'B');
}