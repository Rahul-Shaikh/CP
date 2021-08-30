#include <iostream>

using namespace std;

int upper_bound(int* arr, int n, int val ) {
    int st = 0, en = n-1;
    int res = -1;
    while (st <= en) {
        int mid = st + (en-st)/2;

        if (arr[mid] <= val) st = mid+1;
        else {
            res = arr[mid];
            en = mid-1;
        }
    }

    return res;
}

int lower_bound(int * arr, int n, int val) {
    int st = 0, en = n-1;
    int res = -1;
    while (st <= en) {
        int mid = st + (en -st )/2;

        if (arr[mid] > val) {
            res = arr[mid];
            en = mid-1;
        }
        else if (arr[mid] == val) return arr[mid];
        else st = mid+1;
    }
    return res;
}

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int val;
    cin >> val;
    cout << upper_bound(arr, n, val) << endl;;
    cout << lower_bound(arr, n, val) << endl;
}