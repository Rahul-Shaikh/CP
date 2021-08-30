
vector<vector<int> > dp;
int solve(string s1, string s2, int i, int j) {

    if (i == s1.size() && j == s2.size()) return 0;

    if (i == s1.size()) {
        return s2.size() - i;
    }

    if (j == s2.size()) {
        return s1.size() - j;
    }
    if (dp[i][j] != -1) return dp[i][j];

    int op = 0;
    if (s1[i] == s2[j]) return solve(s1, s2, i+1, j + 1);
    else {
        int mn = min(solve(s1, s2, i+1, j+1), solve(s1, s2, i+1, j));
        mn = min(solve(s1, s2, i, j+1), mn);
        op = 1 + mn;
    }

    return dp[i][j]=op;
}


int main(void) {
    string s1,s2;
    cin >> s1 >> s2;
    dp = vector<vector<int> > (s1.size() + 1, vector<int> ( s2.size() +1 ,-1));
    cout << solve(s1, s2, 0, 0);
}