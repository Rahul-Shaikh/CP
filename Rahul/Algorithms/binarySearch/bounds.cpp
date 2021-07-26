#include <iostream>

using namespace std;

int upper_bound(int *arr, int st, int en, int target) {
    while (st < en) {
        int mid = st + (en-st)/2;

        if (arr[mid] <= target) {
            st = mid+1;
        } else {
            en = mid;
        }

        // cout << st << " " << en << endl;
    }
        if (arr[st] > target) return st;
        if (arr[en] > target) return en;
        return -1;
}

int lower_bound(int *arr, int st, int en, int target) {
    while (st < en) {
        int mid = st + (en-st)/2;

        if (arr[mid] < target) {
            st = mid + 1;
        } else {
            en = mid;
        }

    }
        if (arr[st] >= target) return st;
        if (arr[en] >= target) return en;
        return -1;
}

int main(void) {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i =0; i < n; i++) cin >> arr[i];
    int t;
    cin >>t;
    int ub = upper_bound(arr, 0, n-1, t);
    int lb = lower_bound(arr, 0, n-1, t);

    cout << lb << " " << ub << endl;
}