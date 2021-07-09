#include <iostream>

using namespace std;

void merge(int* arr, int low, int mid, int high) {
    int temp[high-low+1];
    int k = 0;
    int i = low, j= mid+1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            k++, i++;
        }
        else {
            temp[k] = arr[j];
            k++, j++;
        }
    }
    while(i<=mid) {
        temp[k++] = arr[i++];
    }
    while(j <= mid) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < k; i++) {
        arr[low+i] = temp[i];
    }
}

void mergesort(int *arr, int low, int high) {

    if (low < high) {
        int mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

int main(void) {
    cout << "mergesort" << endl;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i< n; i++) cout << arr[i] << " ";
    cout << endl;
    mergesort(arr, 0, n-1);
    for (int i = 0; i< n; i++) cout << arr[i] << " ";
    cout << endl;
}