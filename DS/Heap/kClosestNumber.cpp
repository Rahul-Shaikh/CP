#include <iostream>
#include <queue>
#include <utility>


using namespace std;
typedef pair<int, int> pi;

int main(void) {
    int n, k, x;
    cin >> n >> k >> x;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    priority_queue<pi> pq;
    for (int i = 0; i < n; i++) {
        pq.push(make_pair(abs(arr[i]-x), i));
        if (pq.size() > k){
            pq.pop();
        }
    }

    while (!pq.empty()) {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
    cout << endl;
}