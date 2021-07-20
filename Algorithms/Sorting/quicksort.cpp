#include <iostream>

using namespace std;

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int itr = low; itr < high; itr++) {
        if (arr[itr] < pivot) {
            swap(arr[itr], arr[i]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
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