class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> matrix) {
        int A = matrix.size(), B = matrix[0].size();
        vector<vector<int>> res(B, vector<int>(A, 0));
        for (int j = 0; j < B; j++)
            for (int i = 0; i < A; i++)
                res[j][i] = matrix[i][j];
        return res;
    }
};
