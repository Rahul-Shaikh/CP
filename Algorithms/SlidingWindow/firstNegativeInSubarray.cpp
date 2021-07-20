#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int i = 0, j = 0;
    queue<int> q;
    queue<int> ans;
    while (j < n) {
        if (arr[j] < 0) q.push(arr[j]);

        if (j - i + 1 < k) j++;
        else if (j - i + 1 == k) {
            if (q.empty()) ans.push(0);
            else ans.push(q.front());

            if (q.front() == arr[i]) q.pop();
            i++, j++;
        }
    }

    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }

    cout << endl;
}