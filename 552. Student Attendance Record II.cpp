class Solution {
public:
    int checkRecord(int n) {
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    dp[0][0][0] = 1; 
    const int MOD = 1e9 + 7;
    
    for (int i = 0; i < n; ++i) {
        for (int A = 0; A < 2; ++A) {
            for (int L = 0; L < 3; ++L) {
                dp[i+1][A][0] = (dp[i+1][A][0] + dp[i][A][L]) % MOD;
                if (A + 1 < 2)
                    dp[i+1][A+1][0] = (dp[i+1][A+1][0] + dp[i][A][L]) % MOD;
                if (L + 1 < 3)
                    dp[i+1][A][L+1] = (dp[i+1][A][L+1] + dp[i][A][L]) % MOD;
            }
        }
    }
    int res = 0;
    for (int A = 0; A < 2; ++A) {
        for (int L = 0; L < 3; ++L) {
            res = (res + dp[n][A][L]) % MOD;
        }
    }
    return res;
    }
};
