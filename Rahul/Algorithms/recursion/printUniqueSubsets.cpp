#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > ans;

vector<vector<int> > subsetsWithDupIter(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int> > ans;
    
    int ansSize = 0;
    sort(nums.begin(), nums.end());
    ans.push_back(vector<int> ());
    for (int i = 0; i < n; i++) {
        int st = 0;
        if (i > 0 && nums[i] == nums[i-1]) {
            st = ansSize;
        }
        ansSize = ans.size();
        for (int j = st; j < ansSize; j++) {
            vector<int> temp = ans[j];
            temp.push_back(nums[i]);
            ans.push_back(temp);
        }
        
    }
    return ans;
}

void util(const vector<int> &nums, int i, vector<int> &temp) {
    ans.push_back(temp);
    int n = nums.size();
    
    for (int j = i; j < n; j++) {
        if (j != i && nums[j] == nums[j-1]) continue;
        temp.push_back(nums[j]);
        util(nums, j + 1,temp);
        temp.pop_back();
    }
}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    if (nums.size() == 0) return ans;
    
    sort(nums.begin(), nums.end());
    vector<int> tmp;
    util(nums, 0, tmp);
    
    return ans;
}

int main(void) {

}