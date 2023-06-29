class Solution {
public:

    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int shortestPathAllKeys(vector<string>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<unsigned long>> map_Key(m, vector<unsigned long>(n, 0));
        int target = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    target |= 1 << (grid[i][j] - 'a');
                    continue;
                }

                if (grid[i][j] == '@') {
                    q.emplace(pair<int, int>(i, j), 0);
                    map_Key[i][j] = 1;
                }
            }
        }


        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                int i = q.front().first.first;
                int j = q.front().first.second;
                int key = q.front().second;
                q.pop();
                
                if ('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    key |= 1 << (grid[i][j] - 'a');
                    if (key == target)
                        return step;

                    map_Key[i][j] |= 1l << key;
                }

                for (int d = 0; d < 4; d++) {
                    int newi = i + dir[d][0];
                    int newj = j + dir[d][1];
                    
                    if (!(0 <= newi && newi < m && 0 <= newj && newj < n))
                        continue;
                        
                    int val = grid[newi][newj];
                    if (val == '#')
                        continue;
                        
                    if ('A' <= val && val <= 'F' && (key & (1 << (val - 'A'))) == 0)
                        continue;
                        
                    if (map_Key[newi][newj] & (1l << key))
                        continue;
                        
                     map_Key[newi][newj] |= 1l << key;
                     q.emplace(pair<int, int>(newi, newj), key);
                }
            }
            step++;
        }
        return -1;
    }
};

