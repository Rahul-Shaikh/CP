#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i< n;i++) cin >> arr[i];

    int t;
    cin >>t;

    int res = -1;
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;

        if (arr[mid] == t) {
            res = arr[mid];
            break;
        } else if (arr[mid] > t) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    //// IF ELEMENT NOT PRESENT LO AND HI POINTS TO THE CLOSEST NEIGHBOURS ////
    if (res != -1) cout << t << endl;
    else  {
        int diff1 = abs(arr[hi]-t);
        int diff2 = abs(arr[lo] - t);
        if (diff1 < diff2) cout << arr[hi] << endl;
        else cout << arr[lo] << endl;
    }
}