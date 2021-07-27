#include <iostream>
#include <cmath>

using namespace std;

char answer(int n, int k) {
    int mxn = pow(2, n-1);
    if (k > mxn) return 'e';
    if (n == 1 && k == 1) return '0';

    int mid = mxn/2;
    if (k <= mid) return answer(n-1, k);
    if (k > mid) {
        char tmp = answer(n-1, k-mid);
        if (tmp == '1') return '0';
        else if (tmp == '0') return '1';
        else return 'e';
    }
    return 'e';
}

int main(void) {
    int n, k;
    cin >> n >> k;

    cout << answer(n, k) << endl;
}