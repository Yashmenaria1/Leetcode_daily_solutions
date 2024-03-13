int dp[1001] = { 0, 0 };
class Solution {
public:
    int pivotInteger(int n) {
        if (dp[1] == 0)
            for (int i = 1, j = 1; i <= 1000; ++i) {
                int sum = i * (i + 1) / 2;
                while (j * j < sum)
                    ++j;
                dp[i] = j * j == sum ? j : -1;
            }
        return dp[n];
    }
};
