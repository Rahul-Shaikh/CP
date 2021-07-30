#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2 ) {
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
}

class Solution {

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        int n = intervals.size();
        bool select[n];
        memset(select, 1, sizeof(select));
        
        for (int i = 1; i < n; i++) {
            if (intervals[i-1][1] >= intervals[i][0]) {
                intervals[i][0] = intervals[i-1][0];
                if (intervals[i-1][1] > intervals[i][1]) intervals[i][1] = intervals[i-1][1];
                select[i-1] = false;
            }
        }
        
        vector<vector<int> > ans;
        for (int i = 0; i < n; i++) {
            if (select[i]) ans.push_back(intervals[i]);
        }
        return ans;
    }
};