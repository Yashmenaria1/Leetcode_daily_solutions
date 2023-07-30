class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int l = 1; l <= n; ++l) {

            for (int i = 0; i <= n - l; ++i) {
                int j = i + l - 1;

                if (i == j) {
                    dp[i][j] = 1;
                } else {
                
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i][j - 1];
                    } else {
                   
                        dp[i][j] = INT_MAX;
                        for (int k = i; k < j; ++k) {
                            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                        }
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
