#include <iostream>

using namespace std;

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;

    for (int itr = low; itr < high; itr++) {
        if (arr[itr] < pivot) {
            i++;
            swap(arr[itr], arr[i]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, pi+1, high);
        quicksort(arr, low, pi-1);
    }
}

int main(void) {
    int n;
    cin >> n;


    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    quicksort(arr, 0, n-1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}