#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void updateRangeUtil(int *st, int *lazy, int ss, int se, int us, int ue, int diff, int si) {
    if (lazy[si]) {
        st[si] += (se - ss + 1) *lazy[si];
        if (ss != se) {
            lazy[2*si+1] += lazy[si];
            lazy[2*si+2] += lazy[si];
        }
        lazy[si] = 0;
    }

    if (ss > se || us > se || ue < ss) return;

    if (us <= ss && ue >= se) {
        st[si] += (ss - se + 1)*diff;

        if (ss != se) {
            lazy[2*si+1] += diff;
            lazy[2*si+2] += diff;
        }
        return;
    }

    int mid = ss + (se - ss)/2;
    updateRangeUtil(st, lazy, ss, mid, us, ue, diff, 2*si+1);
    updateRangeUtil(st, lazy, mid+1, se, us, ue, diff, 2*si+2);

    st[si] = st[2*si+1] + st[2*si+2];
}

void updateRange(int* st, int* lazy, int n, int us, int ue, int diff) {
    if (us < 0 || ue > n-1 || us > ue) return;

    updateRangeUtil(st, lazy, 0, n-1, us, ue, diff, 0);
}

void updateUtil(int *st, int ss, int se, int i, int diff, int si) {
    if (i < ss || i > se) return;

    st[si] += diff;

    if (ss != se) {
        int mid = ss + (se - ss)/2;
        updateUtil(st, ss, mid, i, diff, 2*si+1);
        updateUtil(st, mid+1, se, i, diff, 2*si+2);
    }
}

void update(int *arr, int *st, int n, int i, int val) {
    if (i > n-1 || i < 0) return;

    int diff = val-arr[i];
    arr[i] = val;

    updateUtil(st, 0, n-1, i, diff, 0);
}

int getSumUtil(int *st, int* lazy, int ss, int se, int qs, int qe, int si) {
    if (lazy[si]) {
        st[si] += (se - ss + 1) * lazy[si];
        if (ss != se) {
            lazy[2*si+1] += lazy[si];
            lazy[2*si+2] += lazy[si];
        }

        lazy[si] = 0;
    }
    if (qs <= ss && qe >= se) return st[si];

    if (qs > se || qe < ss || ss > se) return 0;

    int mid = ss + (se - ss)/2;

    return getSumUtil(st, lazy, ss, mid, qs, qe, 2*si + 1) + getSumUtil(st, lazy, mid+1, se, qs, qe, 2*si+2);
}

int getSum(int *st, int* lazy, int n, int qs, int qe) {
    if (qs < 0 || qe > n-1 || qs > qe) return -1;

    return getSumUtil(st, lazy, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int *st, int *arr, int ss, int se, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return st[si];
    }

    int mid = ss + (se-ss)/2;
    return st[si] = constructSTUtil(st, arr, ss, mid, 2*si+1) + constructSTUtil(st, arr, mid+1, se, 2*si+2);
}

void *constructST(int *arr, int n, int* &st, int* &lazy) {
    int x = (int)ceil(log2(n));
    int mxsize = 2*(int)pow(2,x) -1;

    st = new int[mxsize];
    lazy = new int[mxsize];
    
    memset(lazy, 0, sizeof(lazy));
    memset(st, 0, sizeof(st));

    for (int i = 0; i < mxsize; i++) {
        lazy[i] = st[i] = 0;
    }
    cout << endl;
    for (int i = 0; i < mxsize; i++) {
        cout << st[i] << " ";
    }
    cout << endl;
    constructSTUtil(st, arr, 0, n-1, 0);
}

int main(void) {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    // Build segment tree from given array
    int* st, *lazy;
    constructST(arr, n, st, lazy);
    
    cout << "constructed\n";
    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
           getSum(st, lazy, n, 1, 3));
  
    // Add 10 to all nodes at indexes from 1 to 5.
    updateRange(st, lazy, n, 1, 5, 10);
  
    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",
            getSum(st, lazy, n, 1, 3));
  
    return 0;
}