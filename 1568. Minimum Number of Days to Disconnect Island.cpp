class Solution {
public:
    int n, m, ones = 0;
    vector<int> DIR = {1, 0, -1, 0, 1};
    int islands(vector<vector<int>>& grid){   
        vector<vector<int>> A(grid.begin(), grid.end());
        int count = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(A[i][j])
                    helper(i, j, A), count++;
        return count;
    }
    void helper(int i, int j, vector<vector<int>>& A){
        if(i < 0 || i == n || j < 0 || j == m || !A[i][j])
            return;
        A[i][j] = 0;
        for(int k = 0; k < 4; k++)
            helper(i + DIR[k], j + DIR[k + 1], A);
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ones += grid[i][j];
        if(islands(grid) > 1) return 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    if(islands(grid) > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return min(2, ones);
    }
};
