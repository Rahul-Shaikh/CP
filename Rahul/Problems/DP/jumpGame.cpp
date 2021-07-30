#include <iostream>
#include <vector>

using namespace std;

bool canJumpDP(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return true;
    
    bool dp[n];
    memset(dp, 0, sizeof(dp));
    
    dp[0] = true;
    
    for (int i = 0; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            if (dp[j] && nums[j] + j >= i) {
                dp[i] = true;
                break;
            }
        } 
    }
    
    for (int i = 0; i < n; i++) cout << dp[i] << " ";

    
    return dp[n-1];
    
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int goodPos = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (nums[i] + i >= goodPos) {
            goodPos = i;
        }
    }

    return goodPos == 0;
}
















