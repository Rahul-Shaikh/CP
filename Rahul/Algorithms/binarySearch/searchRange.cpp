#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    
    vector<int> ans(2, -1);
    int st = 0, en = n-1;
    while (st <= en) {
        int mid = st + (en-st)/2;
        
        if (nums[mid] == target) {
            ans[0] = mid;
            en = mid-1;
        }
        
        else if (nums[mid] > target) {
            en = mid -1;
        }
        else st = mid + 1;
    }
    
    st = 0, en = n-1;
    while (st <= en) {
        int mid = st + (en-st)/2;
        
        if (nums[mid] == target) {
            ans[1] = mid;
            st = mid+1;
        }
        
        else if (nums[mid] > target) {
            en = mid -1;
        }
        else st = mid + 1;
    }
    
    return ans;
}

int main(void) {
    int n, t;
    cin >> n >> t;

    vector<int> v(n, 0);
    for (int i =0; i < n; i++) cin >> v[i];

    vector<int> ans= searchRange(v, t);
    cout << ans[0] << " " << ans[1];
}