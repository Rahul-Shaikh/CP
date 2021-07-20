#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    list<int> l;
    queue<int> ans;
    int i = 0, j = 0;
    while (j < n) {
        if (l.empty()) l.push_back(arr[j]);
        else if (arr[j] > l.front()) {
            while (!l.empty()) l.pop_front();
            l.push_back(arr[j]);
        }
        else {
            while (arr[j] > l.back()) l.pop_back();
            l.push_back(arr[j]);
        }

        if (j-i+1 < k) j++;
        else if (j-i+1 == k) {
            ans.push(l.front());
            if (arr[i] == l.front()) {
                l.pop_front();
            }
            i++, j++;
        }
    }

    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
}