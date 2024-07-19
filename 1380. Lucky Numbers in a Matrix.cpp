class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;

        for(int i = 0; i<matrix.size(); i++){
            int mini = INT_MAX;
            for(int j = 0; j<matrix[0].size(); j++){
                mini = min(mini, matrix[i][j]);
            }
            res.push_back(mini);
        }
        for(int i = 0; i<matrix[0].size(); i++){
            int maxi = INT_MIN;
            for(int j = 0; j<matrix.size(); j++){
                maxi = max(maxi, matrix[j][i]);
            }
            res.push_back(maxi);
        }
        unordered_map<int, int> mp;
        for(int i = 0; i<res.size(); i++){
            mp[res[i]]++;
        }
        vector<int>ans;
        for(auto m:mp){
            if(m.second == 2){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};
