#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int k1, k2;
    cin >> k1 >> k2;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    priority_queue<int> pq;
    for (int i = 0; i< n; i++) {
        pq.push(arr[i]);
        if (pq.size() > max(k1,k2)) {
            pq.pop();
        }
    }

    cout << max(k1,k2) << "th smallest element: " << pq.top();
    pq.pop();
    cout << endl << "between elements: ";
    while (pq.size() > min(k1, k2)) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout <<endl<< min(k1,k2) << "th smallest element: " << pq.top() <<endl;
    pq.pop();

    if (!pq.empty()) cout << "Rest are: " ;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}