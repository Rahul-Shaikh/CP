#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int findMax(int* arr, int n) {
    int mx = 0;
    int mask = 0;

    set<int> s;
    for (int i = 30; i >= 0; i--) {
        mask = mask | (1 << i);
        int newmx = mx | (1 << i);
        for (int j = 0; j < n; j++) {
            s.insert(arr[j] & mask);
        }

        for (int pre: s) {
            if (s.count(newmx ^ pre)) {
                mx = newmx;
                break;
            }
        }
        s.clear();
    }    

    return mx;
}

int main(void) {

}