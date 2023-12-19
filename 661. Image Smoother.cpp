class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<pair<int, int>> neighbors({{-1,-1}, {0,-1}, {1,-1}, {-1,0}, {0,0}, {1,0}, {-1,1}, {0,1}, {1,1}});
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0, count = 0;
                
                for(const auto& neighbor: neighbors) {
                    int x = i + neighbor.first, y = j + neighbor.second;
                    
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        sum += img[x][y];
                        count++;
                    }
                }
                
                ans[i][j] = static_cast<int>(sum / static_cast<double>(count));
            }
        }
        
        return ans;
    }
};
