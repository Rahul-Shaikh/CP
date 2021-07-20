#include <iostream>
#include <stack>
#include <deque>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    stack<int> s;
    deque<int> ans;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() < arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans.push_back(-1);
        }else {
            ans.push_back(s.top());
        }
        s.push(arr[i]);
    }

    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop_front();
    }
    cout << endl;
}