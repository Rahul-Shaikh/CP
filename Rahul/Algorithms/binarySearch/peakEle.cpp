#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int res= -1;
    int n = nums.size();
    int lo = 0, hi = n-1;
    if (n == 1) return 0;
    while (lo <= hi) {
        cout << lo << " " << hi << endl;
        int mid = lo + (hi-lo)/2;
        cout << mid << endl;           
        if (mid + 1 == n) {
            if (nums[mid] > nums[mid-1]) {
                res = mid;    
                break;
            } else {
                hi = mid - 1;
            }
        }
        else if (mid-1 == -1) {
            if (nums[mid] > nums[mid+1]) {
                res = mid;   
                break;
            } else {
                lo = mid + 1; 
            }
        }
        else if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
            res = mid;
            break;
        }
        else if (nums[mid] < nums[mid - 1]) {
            hi = mid-1;
        } else {
            lo = mid + 1;
        }
    } 
    return res;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i<n;i++) cin >> nums[i];
    
}
