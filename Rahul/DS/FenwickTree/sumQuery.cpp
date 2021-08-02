#include <iostream>
#include <cstring>

using namespace std;

int getSum(int* BITree, int r) {
    int sum = 0;
    int idx = r+1;

    while (idx > 0) {
        sum += BITree[idx];
        idx = idx - (idx & (-idx));
    }
    return sum;
}

void update(int* BITree, int r, int val, int n) {
    int idx = r+1;

    while (idx <= n) {
        BITree[idx] += val;
        idx += (idx&(-idx));
    }
}

void constructBIT(int* arr, int* BITree, int n) {
    for (int i = 0; i < n; i++) {
        update(BITree, i, arr[i], n);
    }
}

int main(void) {
    int n;
    // cin >> n;

    int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    n = sizeof(arr)/sizeof(arr[0]);
    // for (int i = 0; i < n; i++) cin >> arr[i];

    int BITree[n+1];
    memset(BITree, 0, sizeof(BITree));

    constructBIT(arr, BITree, n);
    for (int i = 0; i < n+1; i++) {
        cout << BITree[i] << " ";
    }
    cout << endl;

    cout << getSum(BITree, 5) << endl;

    update(BITree, 3, 6, n);

    cout << getSum(BITree, 5) << endl;
}