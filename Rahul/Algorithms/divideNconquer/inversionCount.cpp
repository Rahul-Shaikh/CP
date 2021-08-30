#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int merge(vector<int>& nums, vector<int> &temp, int st, int mid, int en) {
    int i = st, j = mid + 1, k = st;
    int inv = 0;
    while (i <= mid && j <= en) {
        if (nums[i] > nums[j]) {
            inv += mid-i+1;
            temp[k++] = nums[j++];
        } else {
            temp[k++] = nums[i++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= en) {
        temp[k++] = nums[j++];
    }

    for (k = st; k <= en; k++) nums[k] = temp[k];

    return inv;
}

int util(vector<int> &nums, vector<int> &temp, int st, int en) {
    int inv = 0;
    if (st < en) {
        int mid = st + (en-st)/2;
        inv += util(nums, temp, st, mid);
        inv += util(nums, temp, mid+1, en);

        inv += merge(nums, temp, st, mid, en);

    }
    return inv;
}

int countInversion(vector<int> &nums) {
    vector<int> temp(nums.size());

    return util(nums, temp, 0, nums.size()-1);
}

int main(void) {
    vector<int> nums {8, 4, 2, 1};
    
    cout << countInversion(nums) << endl;
    for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    cout << endl;
}