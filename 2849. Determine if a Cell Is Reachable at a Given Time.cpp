class Solution {
public:
    bool isReachableAtTime(int s_x, int s_y, int f_x, int f_y, int t) {
    int x_diff = abs(s_x - f_x), y_diff = abs(s_y - f_y);
    if(x_diff == 0 && y_diff == 0 && t == 1) return false;
    return max(x_diff, y_diff) <= t;
    }
};
