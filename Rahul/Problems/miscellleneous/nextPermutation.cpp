#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int itr = n-2;
    while (itr >= 0 && arr[itr+1] <= arr[itr]) itr--;

    if (itr >= 0) {
        int j = n-1;
        while (itr < j && arr[j] <= arr[itr]) j--;
        swap(arr[itr], arr[j]);
        reverse(arr+itr+1, arr+n);
    }else reverse(arr, arr+ n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}