#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
    vector<vector<int> > dp;
    int getSum(vector<int> &stones, int s, int e) {
        int sum = 0;
        for (int i = s; i <= e; i++) {
            sum += stones[i];
        }
        return sum;
    }
        
    int solve(vector<int> &stones, int s, int e, int k) {
        if (s==e) return 0;
        
        if (dp[s][e] != INT_MAX) return dp[s][e];
        if (e-s+1 == k) return dp[s][e] = getSum(stones, s, e);
        
        int sum = 0;
        if ((s-e) % (k-1) == 0) {
            sum = getSum(stones, s, e);
        }
        int res = INT_MAX;
        for (int i = s; i < e; i+= k-1) {
            res = min(res, solve(stones, s, i, k) + solve(stones, i+1, e, k));
        }
        
        return dp[s][e] = res + sum;
    }
    
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n-1)%(k-1) != 0) return -1;
        
        dp = vector<vector<int> > (stones.size()+1, vector<int> (stones.size()+1, INT_MAX));
        
        return solve(stones, 0, stones.size()-1, k);
    }
};