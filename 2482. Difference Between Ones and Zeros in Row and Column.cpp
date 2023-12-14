class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> onesRows(n);
        vector<int> onesCol(m);
        
        vector<int> zerosRow(n);
        vector<int> zerosCol(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    onesRows[i] += 1;
                    onesCol[j] += 1;
                }
                else{
                    zerosRow[i] += 1;
                    zerosCol[j] += 1;
                }
            }
        }
        vector<vector<int>> diff(n,vector<int>(m,0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                diff[i][j] = onesRows[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        return diff;
        
    }
};
