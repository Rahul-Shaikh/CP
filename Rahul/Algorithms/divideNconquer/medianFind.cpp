#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

double median(int* arr, int n) {
    if (n % 2 ==0 ){
        return ((double)arr[n/2] + arr[n/2-1])/2;
    } else {
        return arr[n/2];
    }
}

double findMedian(int* arr1, int* arr2, int n) {
    if (n==1) {
        return ((double)arr1[0] + arr2[0])/2;
    }
    if (n == 2) {
        return ((double)max(arr1[0],arr2[0])+ min(arr1[1], arr2[1]))/2;
    }

    double m1 = median(arr1, n);
    double m2 = median(arr2, n);

    if (n%2 == 0) {
        if (m1 > m2) return findMedian(arr1, arr2+n/2-1, n/2+1);
        return findMedian(arr1 + n/2-1, arr2, n/2+1);
    }
    if (m1 > m2) return findMedian(arr1, arr2+n/2, n/2+1);
    return findMedian(arr1+n/2, arr2, n/2+1);
}

int main(void) {
     int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1) /
             sizeof(ar1[0]);
    int n2 = sizeof(ar2) /
             sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is "
             << findMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays "
             << "of unequal size";
    return 0;
}