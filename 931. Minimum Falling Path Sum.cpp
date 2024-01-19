class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        int ans = INT_MAX;

        for (int i = 0; i < cols; ++i) {
            dp[0][i] = A[0][i];
        }

        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j == 0) {
                    dp[i][j] = A[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                } else if (j == cols - 1) {
                    dp[i][j] = A[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                } else {
                    dp[i][j] = A[i][j] + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]});
                }
            }
        }

        for (int i = 0; i < cols; ++i) {
            ans = min(ans, dp[rows - 1][i]);
        }

        return ans;
    }
};
