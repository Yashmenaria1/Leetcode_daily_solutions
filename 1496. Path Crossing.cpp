class Solution {
public:
    bool isPathCrossing(std::string path) {
        int n = path.length();
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; i++) {
            int tempX = x;
            int tempY = y;
            for (int j = i; j < n; j++) {
                char ch = path[j];
                if (ch == 'N') y++;
                else if (ch == 'S') y--;
                else if (ch == 'W') x--;
                else x++;
                if (x == tempX && y == tempY) return true;
            }
        }
        return false;
    }
};
