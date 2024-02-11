class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return dfs(grid, dp, m, n, 0, 0, n - 1);
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int m, int n, int r, int c1, int c2) {
        if (r == m) return 0; 
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        int cherries = grid[r][c1];
        if (c1 != c2)
            cherries += grid[r][c2];
        
        int maxCherries = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nc1 = c1 + i, nc2 = c2 + j;
                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                    maxCherries = max(maxCherries, dfs(grid, dp, m, n, r + 1, nc1, nc2));
                }
            }
        }
        return dp[r][c1][c2] = maxCherries + cherries;
    }
};
