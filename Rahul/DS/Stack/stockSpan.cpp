#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin  >> arr[i];

    deque<int> ans, s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.back()] < arr[i]) s.pop_back();
        if (s.empty()) ans.push_back(-1);
        else ans.push_back(s.back());

        s.push_back(i);
    }

    for(int i = 0; i < n; i++) {
        cout << i-ans[i]<< " ";
    }
    cout << endl;
}