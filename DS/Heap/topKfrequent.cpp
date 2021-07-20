#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pi;

int main(void) {
    int n,k;
    cin >> n >> k;
    int arr[n];
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        hash[arr[i]]++;
    }

    priority_queue<pi, vector<pi>, greater<pi> > pq;
    for (pair<int, int> v: hash) {
        pq.push(make_pair(v.second, v.first));
        if (pq.size() > k) pq.pop();
    }

    while (!pq.empty()) {
        cout << pq.top().second << "---------->" << pq.top().first << endl;
        pq.pop();
    }


}