#include <iostream>
#include <cstring>

using namespace std;

double median2(int a, int b) {
    return ((double)a + b)/2;
}

double median3(int a, int b, int c) {
    return a+b+c - min(a, min(c,b))-max(a, max(b,c));
}

double median4(int a, int b, int c, int d) {
    int mx = max(a, max(b, max(c, d)));
    int mn = min(a, min(b, min(c, d)));

    return ((double)a+b+c+d-mn-mx)/2;
}

double median(int *arr, int n) {
    if (n%2==0) {
        return ((double)arr[n/2]+arr[n/2-1])/2;
    }
    return arr[n/2];
}

double findMedian(int *arr1, int m, int *arr2, int n) {
    if (m > n) {
        return findMedian(arr2, n, arr1, m);
    }


    if (n==0) {
        return median(arr2, m);
    }
    else if (n==1) {
        if (m == 1) {
            return median2(arr1[0], arr2[0]);
        }
        else if (m%2 == 0) {
            return median3(arr1[0], arr2[m/2], arr2[m/2-1]);
        }
        else if (m%2 == 1){
            return median2(arr2[m/2], median3(arr1[0], arr2[m/2-1], arr2[m/2+1]));
        }
    }
    else if (n==2) {
        if (m == 2) {
            return median4(arr1[0], arr2[0], arr1[1], arr2[1]);
        }
        else if (m%2 == 0) {
            return median4(arr2[m/2], arr2[m/2-1], max(arr1[0], arr2[m/2-1]), min(arr1[1], arr2[m/2+1]));
        }
        else if (m%2 == 1) {
            return median3(arr2[m/2], max(arr2[m/2-1], arr1[0]), min(arr2[m/2+1], arr1[1]));
        }
    }
    else {
        int idxA = (n-1)/2;
        int idxB = (m-1)/2;

        if (arr1[idxA] <= arr2[idxB]) return findMedian(arr1+idxA, n/2+1, arr2, m-idxB);
        return findMedian(arr1, n/2+1, arr2+idxB, m-idxB);
    }
}