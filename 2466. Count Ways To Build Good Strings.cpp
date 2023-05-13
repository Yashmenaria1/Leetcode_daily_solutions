class Solution {
 public:
  int countGoodStrings(int low, int high, int zero, int one) {
    constexpr int kMod = 1000000007;
    int ans = 0;
    vector<int> dp(high + 1);
    dp[0] = 1;

    for (int i = 1; i <= high; ++i) {
      if (i >= zero)
        dp[i] = (dp[i] + dp[i - zero]) % kMod;
      if (i >= one)
        dp[i] = (dp[i] + dp[i - one]) % kMod;
      if (i >= low)
        ans = (ans + dp[i]) % kMod;
    }

    return ans;
  }
};
