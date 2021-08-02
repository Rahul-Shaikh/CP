#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void updateUtil(int *st, int ss, int se, int i, int diff, int si) {
    if (i < ss || i > se) return;

    st[si] += diff;
    if (ss != se) {
        int mid = ss + (se-ss)/2;
        updateUtil(st, ss, mid, i, diff, 2*si+1);
        updateUtil(st, mid+1, se, i, diff, 2*si+2);
    }
}

void update(int *arr, int *st, int n, int i, int nval) {
    if (i < 0 || i > n-1) return;

    int diff = nval - arr[i];
    arr[i] = nval;

    updateUtil(st, 0, n-1, i, diff, 0);
}

int getSumUtil(int* st, int ss, int se, int qs, int qe, int si) {
    if (qs <= ss && qe >= se) return st[si];

    if (qs > se || qe < ss) return 0;

    int mid = ss + (se-ss)/2;
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + getSumUtil(st, mid+1, se, qs,qe, 2*si +2);
}

int getSum(int *ST, int n, int qs, int qe) {
    if (qs < 0 || qs > qe || qe > n-1) {
        return 0;
    }

    return getSumUtil(ST, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int *arr, int l, int r, int* st, int si) {
    if (l == r) {
        st[si] = arr[l];
        return st[si];
    }

    int mid = l + (r-l)/2;
    st[si] = constructSTUtil(arr, l, mid, st, 2*si+1) + constructSTUtil(arr, mid+1, r, st, 2*si + 2);
    return st[si];
}

int *constructST(int *arr, int n) {
    int x = (int)ceil(log2(n));
    int v = 2*(int)pow(2, x) - 1;

    int *st = new int[v];
    memset(st, 0, sizeof(st));

    constructSTUtil(arr, 0, n-1, st, 0);
    cout << "constructed\n";
    for (int i = 0; i < v; i++) cout << st[i] << " ";
    cout << endl;
    return st;
}

int main(void) {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    int *st = constructST(arr, n);
 
    // Print sum of values in array from index 1 to 3
    cout<<"Sum of values in given range = "<<getSum(st, n, 1, 3)<<endl;
 
    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    update(arr, st, n, 1, 10);
 
    // Find sum after the value is updated
    cout<<"Updated sum of values in given range = "
            <<getSum(st, n, 1, 3)<<endl;
    return 0;
}