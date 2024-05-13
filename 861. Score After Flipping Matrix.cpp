class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.empty() ? 0 : grid[0].size();
        for (int row = 0; row < n; ++row) {
            if (grid[row][0] == 0) {
                for (int col = 0; col < m; ++col) {
                    grid[row][col] = 1 - grid[row][col];
                }
            }
            assert(grid[row][0] == 1);
        }
        int base = 1;
        int ans = 0;
        for (int col = m-1; col >= 0; --col) {
            int cnt = 0;
            for (int row = 0; row < n; ++row) {
                cnt += grid[row][col];
            }
            ans += base * max(cnt, n - cnt);
            base *= 2;
        }
        return ans;
    }
};
