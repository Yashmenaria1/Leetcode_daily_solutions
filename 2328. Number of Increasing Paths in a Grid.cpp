class Solution {
public:
    int mod = 1000000007;
    vector<int> dir = {-1, 0, 1, 0, -1};

    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (dp[row][col] != -1)
            return dp[row][col];

        long long ans = 0;
        for (int k = 0; k < 4; k++) {
            int newRow = row + dir[k];
            int newCol = col + dir[k + 1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > grid[row][col])
                ans = (ans + dfs(newRow, newCol, grid, dp)) % mod;
        }
        return dp[row][col] = (ans + 1) % mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = (ans + dfs(i, j, grid, dp)) % mod;
            }
        }
        return static_cast<int>(ans);
    }
};
