#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if (n > m) return findMedianSortedArrays(nums2, nums1);
        
        int st = 0;
        int en = n;
        int midInMerge = (m+n+1)/2;
        while (st<=en) {
            int mid = st + (en-st)/2;
            int leftASize = mid;
            int leftBSize = midInMerge-mid;
            
            int leftA = (leftASize > 0) ? nums1[leftASize-1] : INT_MIN;
            int leftB = (leftBSize > 0) ? nums2[leftBSize-1] : INT_MIN;
            int rightA = (leftASize < n) ? nums1[leftASize] : INT_MAX;
            int rightB = (leftBSize < m) ? nums2[leftBSize] : INT_MAX;
            
            if (leftA <= rightB && leftB <= rightA) {
                if ((m+n)%2) return max(leftA, leftB);
                else {
                    return (min(rightA, rightB) + max(leftA, leftB))/2.0;
                }
            }
            else if (leftA > rightB) {
                en = mid-1;
            }
            else st = mid+1;
        }
        return 0.0;
    }
};

int main(void) {
    
}