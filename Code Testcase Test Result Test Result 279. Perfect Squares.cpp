class Solution {
public:
    int solve(int n, vector<int>&dp){
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        
        int mnCount = INT_MAX;
        for (int num = 1; num <= sqrt(n); num++){
            int sqNum = num * num;
            int currCount = 1 + solve(n - sqNum, dp);
            mnCount = min(mnCount, currCount);
        }
        return dp[n] = mnCount;
    }
    int numSquares(int n) {
        vector<int>dp(n + 1, -1);
        return solve(n, dp);
    }
};
