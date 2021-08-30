#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > vvi;

bool cmp(vector<int> &v1, vector<int> &v2) {
    if (v1[1] == v2[1]) return v1[0] < v2[0];
    return v1[1] < v2[1];
}

vvi solve(vvi& inter) {
    vvi ans;
    ans.push_back(inter[0]);

    int end = inter[0][1];

    for (int i = 1; i < inter.size(); i++) {
        // cout << i << endl;
        int st = inter[i][0];
        int en = inter[i][1];

        if (end < st) {
            ans.push_back(inter[i]);
            end = en;
        }
    }
    return ans;
}

int main(void) {
    int n;
    cin >> n;

    vvi intervals;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals.push_back({l, r});
    }

    sort(intervals.begin(), intervals.end(), cmp);

    // for (int i = 0; i < intervals.size(); i++) {
    //     cout << intervals[i][0] << " " << intervals[i][1] << endl;
    // }

    vvi ans = solve(intervals);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}
