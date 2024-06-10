class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> expected(n);
        for(int i = 0; i<n; i++){
            expected[i] = heights[i];
        }
        sort(expected.begin(), expected.end());
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(expected[i] != heights[i]){
                ans++;
            }
        }
        return ans;
    }
};
