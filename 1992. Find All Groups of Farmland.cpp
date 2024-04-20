class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size(), n = land[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0) continue;
                
                int c2 = j + 1;
                while (c2 < n && land[i][c2] == 1) c2++; 
                
                int r2 = i + 1;    
                while (r2 < m && land[r2][j] == 1) r2++;
                    
                c2 -= 1;
                r2 -= 1;
                
                ans.push_back({i, j, r2, c2});
                
                for (int k = i; k <= r2;k++)
                    for (int l = j; l <= c2; l++)
                        land[k][l] = 0;
            }
        }
        
        return ans;
    }
};
