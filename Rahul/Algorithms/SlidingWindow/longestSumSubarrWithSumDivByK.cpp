#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <climits>

using namespace std;

void solve(vector<int> &arr, int k) {
    int n = arr.size();
    unordered_map<int, int> um;
    int total = accumulate(arr.begin(), arr.end(), 0);
    int target_remainder = total % k;

    if (target_remainder == 0) return;

    int curr_remainder = 0;
    int ans = INT_MAX;
    int idx = 0;
    vector<int> vans;
    um[0] = -1;
    for (int i = 0; i < n; i++) {
        curr_remainder = (curr_remainder + arr[i] + k)%k;
        um[curr_remainder] = i;
        // cout << curr_remainder << endl;
        int required_rem = (curr_remainder - target_remainder +  k) % k;
        if (um.count(required_rem)) {
            if (ans > i - um[required_rem]) {
                ans = i- um[required_rem];
                idx = i - ans + 1;
            }
        }
    }

    // cout << ans << endl;

    if (ans == arr.size())  {
        cout << "no solution" << endl;
        return;
    }
    for (int j = 0; j < ans; j++) {
        cout << arr[j + idx] << " ";
    }
    cout << endl;

    // return vans;
}

// 6 3 5 2 = 16
// 7
// 9

// 6 = 0
// 0 = 1
// 5 = 2
// 7 = 3

// 6 - 7 + 9 = 

int main(void) {
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solve(arr, k);
}