#include <iostream>

using namespace std;

int findMin(int *arr, int n)
{
    int lo = 0;
    int hi = n - 1;

    while (lo < hi)
    {

        while (lo < n - 1 && arr[lo + 1] == arr[lo])
            lo++;
        while (hi >= 1 && arr[hi - 1] == arr[hi])
            hi--;
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] > arr[hi])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }

    return lo;
}

// int findMin2(int* arr, int n) {
//     int res = -1;
//     int lo = 0, hi = n - 1;
//     while (lo <= hi) {
//         int prevlo = lo;
//         while (lo < n - 1 && arr[lo + 1] == arr[lo])
//             lo++;
//         while (hi >= 1 && arr[hi - 1] == arr[hi])
//             hi--;

//         if (lo > hi) {
//             res = prevlo;
//             break;
//         }

//         int mid = lo + (hi-lo)/2;
//         int next = (mid + 1)%n;
//         int prev = (mid + n - 1) %n;

//         if (arr[mid] > arr[prev] && arr[mid] <= arr[next]) {
//             res = mid;
//             break;
//         }
//         else if (arr[mid] > arr[lo]) {

//         }
//         else {

//         }
//     }
// }

int main(void)
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << findMin(arr, n) << endl;
}