class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<int> cols(n), row(m);
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (mat[i][j] == 1){
                    cols[j]++;
                    row[i]++;
                } 
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (mat[i][j] == 1 && row[i] == 1 && cols[j] == 1) 
                    res++;
        return res;
    }
};
