#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int k; cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    priority_queue<int, vector<int>, greater<int> > pq; // for large min for small max heap

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    cout << pq.top() << endl;
}