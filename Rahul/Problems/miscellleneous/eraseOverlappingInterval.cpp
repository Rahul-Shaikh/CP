#include<iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2) {
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
}

class Solution {

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        if (n == 0) return 0;
        int cnt = 0;
        int prev = 0;
        for (int i = 1; i < n; i++) {
            // cout << prev[0] << " " <<prev[1] << endl;
            if (intervals[prev][1] > intervals[i][0]) {
                if (intervals[prev][1] > intervals[i][1]) {
                    prev = i;   
                }
                cnt++;
            }
            else {
                prev = i;
            }
        }
        
        return cnt;
    }
};