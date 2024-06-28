class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);
        long long res = 0;
        for(auto& r : roads){
            ++degree[r[0]];
            ++degree[r[1]];
        }
        sort(degree.begin(), degree.end());
        for(int i = 0; i<n; i++){
            res += degree[i]*(i+1);
        }
        return res;
    }
};
