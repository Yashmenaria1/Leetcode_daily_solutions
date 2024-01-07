class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int total = 0;
        vector<unordered_map<long long, int>> dp(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j];
                dp[i][diff] += 1;
                if (dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    total += dp[j][diff];
                }
            }
        }
        return total;
    }
};
