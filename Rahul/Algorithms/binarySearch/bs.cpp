#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int t;
    cin >> t;
    int lo = 0, hi = n - 1;
    int res = -1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;

        // if (lo == hi) {
        //     if (arr[lo] == t) {
        //         res = mid;
        //     }
        //     break;
        // } 
        
        if (arr[mid] == t) {
            res = mid;
            break;
        }
        else if (arr[mid] > t) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << res << endl;
}