#include <iostream>
#include <vector>

using namespace std;
// find pivot and then binary search


// duplicate elements
bool searchUtil2(vector<int> &nums, int l, int r, int t) {
        if (l > r) return false;
        
        int mid = l + (r-l)/2;
        if (nums[mid] == t) return true;
        
        if (nums[l] == nums[r] && nums[l] == nums[mid]) {
            l++, r--;
            return searchUtil2(nums, l, r, t);
        }
        
        if (nums[mid] <= nums[r]) {
            if (t > nums[mid] && t <= nums[r]) return searchUtil2(nums, mid+1, r, t);
            else return searchUtil2(nums, 0, mid-1, t);
        }
        if (t < nums[mid] && t >= nums[l]) return searchUtil2(nums, 0, mid-1, t);
        else return searchUtil2(nums, mid + 1, r,t);
    }

int searchUtil(vector<int> nums, int l, int r, int t) {
    if (l > r) return -1;
    
    int mid = l + (r-l)/2;
    
    if (nums[mid] == t) return mid;
    if (nums[l] <= nums[mid]) {
        if (nums[mid] > t  && t >= nums[l]) return searchUtil(nums, l, mid-1, t);
        else return searchUtil(nums, mid+1, r, t);
    }
    if (nums[mid] < t && nums[r] >= t) return searchUtil(nums, mid+1, r, t);
    
    return searchUtil(nums, l, mid-1, t);
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    return searchUtil(nums, 0, n-1, target);
}

int main(void) {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i<n;i++) cin >> nums[i];
}