#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

bool greater_(int i, int j) {
    return i > j;
}

class MyGreater {
    public:
    bool operator() (int i, int j) {
        return i > j;
    }
};

int main(void) {
    int arr[] = {1,5,3,4,8,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    // sort(arr, arr+n);
    // sort(arr,arr+n,greater<int>());
    // sort(arr, arr +n, greater_);
    // sort(arr, arr+n, MyGreater); //////error

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}