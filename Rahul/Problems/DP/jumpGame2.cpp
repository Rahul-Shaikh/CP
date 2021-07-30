#include <iostream>
#include <vector>

using namespace std;

int jumpDP(vector<int>& nums) {
    int n = nums.size();
    int dp[n];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i < n; i++) {
        int mn = INT_MAX;
        for (int j = i-1; j >= 0; j--) {
            if (nums[j] + j >= i) mn = min(mn, 1 + dp[j]);
        }
        dp[i] = mn;
    }
    
    return dp[n-1];
}

int jumpLinear(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;
    if (nums[0] == 0) return -1;
    int steps = nums[0];
    int maxReach = nums[0];
    int jump = 1;
    
    for (int i = 1; i < n; i++) {
        if (i == n-1) return jump;
        
        maxReach = max(maxReach, i + nums[i]);
        
        steps--;
        
        if (steps == 0) {
            jump++;
            
            if (i >= maxReach) return -1;
            
            steps = maxReach - i;
        }
    }
    
    return -1;
}