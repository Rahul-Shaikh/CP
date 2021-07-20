#include <iostream>
#include <deque>
#include <vector>


using namespace std;

deque<int> NSR(vector<int> arr) {
    deque<int> ans, s;
    for (int i = arr.size()-1; i >= 0; i--) {
        while (!s.empty() && arr[s.back()] > arr[i]) s.pop_back();
        if (s.empty()) ans.push_front(arr.size());
        else ans.push_front(s.back());

        s.push_back(i);
    }

    return ans;
}

deque<int> NSL(vector<int> arr) {
    deque<int> ans, s;
    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[s.back()] > arr[i]) s.pop_back();
        if (s.empty()) ans.push_back(-1);
        else ans.push_back(s.back());

        s.push_back(i);
    }

    return ans;
}

int maxAreaHist(vector<int> arr) {
    deque<int> lsmall = NSL(arr), rsmall = NSR(arr);

    int mx = -1;
    for (int i = 0; i < arr.size(); i++) {
        mx = max(mx, arr[i] * (rsmall[i]-lsmall[i] - 1));
    }

    return mx;
}

int solve(vector<vector<int> > arr) {
    vector<int> row(arr[0].size(), 0);
    int mx = -1;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            if (arr[i][j] == 0) row[j] = 0;
            else row[j] += arr[i][j];
            // cout << row[j] << " "; 
        }
        // cout << endl;
        mx = max(mx, maxAreaHist(row));
    }

    return mx;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > arr(n, vector<int> (m, 0));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solve(arr) << endl;

}