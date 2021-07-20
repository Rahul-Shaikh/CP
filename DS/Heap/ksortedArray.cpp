#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n;
    int k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    priority_queue<int, vector<int>, greater<int> > pq;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if (pq.size() > k+1) {
            arr[idx] = pq.top();
            pq.pop();
            idx++;
        }
    }

    while (idx < n && !pq.empty()) {
        arr[idx++] = pq.top();
        pq.pop();
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}