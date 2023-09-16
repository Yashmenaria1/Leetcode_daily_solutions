class Solution {
private:
    bool visited[105][105];  
    int directions_x[4] = {0, 1, -1, 0};  
    int directions_y[4] = {1, 0, 0, -1};  
    int row, col;  

public:
    void dfs(int x, int y, int limitEffort, vector<vector<int>>& heights){
        if (visited[x][y])
            return;
        visited[x][y] = true;

        if (x == row - 1 && y == col - 1)
            return ;

        for (int i = 0; i < 4; i++) {
            int new_x = x + directions_x[i];
            int new_y = y + directions_y[i];

            if (new_x < 0 || new_x >= row || new_y < 0 || new_y >= col)
                continue;
            
            int newEffort = abs(heights[x][y] - heights[new_x][new_y]);
            if (newEffort <= limitEffort)
                dfs(new_x, new_y, limitEffort, heights);
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        row = heights.size(); 
        col = heights[0].size();

        int begin = 0, end = 1e6;

        while (begin < end) {
            int mid = begin+ (end - begin) / 2;
            memset(visited, 0, sizeof visited);
            dfs(0, 0, mid, heights);

            if (visited[row - 1][col - 1])
                end = mid;
            else
                begin = mid + 1;
        }

        return begin;
    }
};
