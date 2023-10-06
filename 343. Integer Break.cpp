class Solution {
public:
    
    int integerBreak(int n) {
        if (n < 2) {
            return 0;
        }

        vector<int> dp(n + 1);
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }

        return dp[n];
    }
};
