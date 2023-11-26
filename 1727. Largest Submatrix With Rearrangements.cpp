class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix[0].size(); i++){
            for (int j = 1; j < matrix.size(); j++) 
                if (matrix[j][i]) matrix[j][i] += matrix[j - 1][i];
		}
        int ans = 0;
        for (auto& v : matrix){
            sort(v.begin(), v.end(), greater <>()); 
            for (int i = 0; i < v.size(); i++) 
                ans = max(ans, v[i] * (i + 1));
		}
        return ans;
    }
};
