#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int> > ds{{0,1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int> > dp;
    
    int dfs(vector<vector<int> > &matrix, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        int mx = 0;
        for (vector<int> d: ds) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size() && matrix[i][j] > matrix[x][y]) {
                mx = max(mx, dfs(matrix, x, y));
            }
        }
        return dp[i][j] = ++mx;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size();
        dp = vector<vector<int> > (n+1, vector<int> (m+1, -1));        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};