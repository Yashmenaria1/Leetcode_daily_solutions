using pathType = pair<int, int>;

class Solution {
    int startMark = -1, endMark = -2;
    queue<pathType> q1{{{0, 0}}}, q2;
    void markAndAdd(vector<vector<int>> &grid, int x, int y) {
        grid[y][x] = startMark;
        q1.push({x, y});
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int t = grid.size() - 1, res = bool(t), qLen = 1, cx, cy, x, y, currVal;
        if (grid[0][0] || grid[t][t]) return -1;
        q2.push({t, t});
        grid[0][0] = startMark;
        grid[t][t] = endMark;
        while (qLen) {
            res++;
            while (qLen--) {
                auto &front = q1.front();
                cx = front.first;
                cy = front.second;

                if (grid[cy][cx] == endMark) return res;
                q1.pop();

                x = cx - 1, y = cy - 1;
                if (x >= 0 && y >= 0) {
                    currVal = grid[y][x];
                    if (currVal == endMark) return res;
                    if (!currVal) markAndAdd(grid, x, y);
                }
                x = cx + 1;
                if (x <= t && y >= 0) {
                    currVal = grid[y][x];
                    if (currVal == endMark) return res;
                    if (!currVal) markAndAdd(grid, x, y);
                }
                y = cy + 1;
                if (x <= t && y <= t) {
                    currVal = grid[y][x];
                    if (currVal == endMark) return res;
                    if (!currVal) markAndAdd(grid, x, y);
                }
                x = cx - 1;
                if (x >= 0 && y <= t) {
                    currVal = grid[y][x];
                    if (currVal == endMark) return res;
                    if (!currVal) markAndAdd(grid, x, y);
                }
                y = cy;
                if (x >= 0) {
                    currVal = grid[y][x];
                    if (currVal == endMark) return res;
                    if (!currVal) markAndAdd(grid, x, y);
                }
                x = cx + 1;
                if (x <= t) {
                    currVal = grid[y][x];
                    if (currVal == endMark) return res;
                    if (!currVal) markAndAdd(grid, x, y);
                }
                x = cx, y = cy - 1;
                if (y >= 0) {
                    currVal = grid[y][x];
                    if (currVal == endMark) return res;
                    if (!currVal) markAndAdd(grid, x, y);
                }
                y = cy + 1;
                if (y <= t) {
                    currVal = grid[y][x];
                    if (currVal == endMark) return res;
                    if (!currVal) markAndAdd(grid, x, y);
                }
            }
            swap(q1, q2);
            swap(startMark, endMark);
            qLen = q1.size();
        }
        return -1;
    }
};
