#include <iostream>
#include <numeric>

using namespace std;

bool isValid(int *w, int mx, int k, int n) {
    int sum = 0;
    int ship = 1;
    for (int i= 0; i < n; i++) {
        sum += w[i];
        if (sum > mx) {
            sum = w[i];
            if (sum > mx) return false;
            ship++;
        }
        if (ship > k) return false;
    }
    return true;
}

int solve(int* weights, int days, int n) {

    int lo = *min_element(weights, weights + n);
    int hi = accumulate(weights, weights + n, 0);
    int res = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        cout << lo << " " << hi << endl;
        
        if (isValid(weights, mid, days, n)) {
            res = mid;
            hi = mid-1;
        } else {
            lo = mid + 1;
        }
    }
    
    return res;
}

int main(void) {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int k;
    cin >> k;

    cout << solve(arr, k, n);
}