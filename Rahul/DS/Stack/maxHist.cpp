#include <iostream>
#include <stack>
#include <vector>
#include <deque>

using namespace std;

vector<int> NSL(int* arr, int n) {
    stack<int> s;
    deque<int> ans;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
        if (s.empty()) ans.push_back(-1);
        else ans.push_back(s.top());

        s.push(i);
    }

    return vector<int> (ans.begin(), ans.end());
}
vector<int> NSR(int* arr, int n) {
    stack<int> s;
    deque<int> ans;
    for (int i = n-1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
        if (s.empty()) ans.push_front(n);
        else ans.push_front(s.top());

        s.push(i);
    }

    return vector<int> (ans.begin(), ans.end());
}

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i =0; i < n; i++) cin >> arr[i];

    vector<int> lsmall = NSL(arr, n), rsmall = NSR(arr, n);

    int mx = -1;
    for (int i = 0; i < n; i++) {
        mx = max(mx, arr[i] * (rsmall[i] - lsmall[i]-1));
    }
    cout << mx << endl;
}