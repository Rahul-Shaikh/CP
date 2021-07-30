#include <iostream>
#include <queue>
#include <vector>
#include <cmath>


using namespace std;
typedef pair<int, int> pi;

bool isValid(int *arr, int n, int disop, int k) {
    int kc = 0;
    cout << disop << endl;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i-1] > disop) {
            cout << arr[i] - arr[i-1] << endl;
            cout << ceil((arr[i] - arr[i-1])/(float)disop) - 1 << endl;
            kc = kc + ceil((arr[i] - arr[i-1])/(float)disop) - 1;
            cout << kc << endl;
            if (kc > k) {
                cout << "break\n";
                return false;
            }
        }
    }
    
    return true;
}

int main(void) {
    int T;
    cin >> T;
    int t  =0;
    while (t++ < T) {
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int mxdiff = 0;
        for (int i = 1; i < n; i++) {
            mxdiff = max(mxdiff, arr[i] - arr[i-1]);
        }
        if (mxdiff <= 1) {
            cout << "Case #" << t << ": " << mxdiff << endl;
            continue;
        }
        int l = 0;
        int r = mxdiff;
        
        int ans = -1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            cout << l << " " << r << endl;
            if (isValid(arr, n, mid, k)) {
                ans = mid;
                if (mid == 1) break; 
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
