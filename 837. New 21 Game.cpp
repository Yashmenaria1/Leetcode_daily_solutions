class Solution {
public:
    double new21Game(int n, int k, int maxPoints) {
        if (k == 0 || n >= k + maxPoints - 1) return 1.0;
        vector<double> dp(n + 1);
        dp[0] = 1.0;
        double WindowSum  = 1.0, ans = 0.0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = WindowSum / maxPoints;
            if (i < k) WindowSum += dp[i];
            else ans += dp[i];
            if (i - maxPoints >= 0) WindowSum -= dp[i - maxPoints];
        }
        return ans;
    }
};
