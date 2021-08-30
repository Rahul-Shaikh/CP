#include <iostream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

int sum(int *arr ,int s, int e) {
    int su = 0;
    for (int i = s; i <= e; i++) {
        su += arr[i];
    }
    return su
    
    ;
}

int solve(int *arr, int s, int e, int k) {
    if (s==e) return arr[s];
    if (s > e) return 0;
    if (k == 1) return sum(arr, s, e);
    int mn = INT_MAX;
    for (int i = s; i < e; i++) {
        int temp = max(sum(arr, s, i), solve(arr, i+1, e, k-1));
        mn = min(mn, temp);
    }

    return mn;

}

int main(void) {
    int arr[] = {10, 20, 60,50, 30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << solve(arr, 0, n-1, k) << endl;
    return 0;
}