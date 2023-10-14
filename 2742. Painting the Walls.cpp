class Solution {
private:
    int minPaintCost(vector<int>& cost, vector<int>& time, int currentIndex, int remainingWalls, vector<vector<int>>& dp) {
        if (remainingWalls <= 0) return 0;
        if (currentIndex < 0) return 1e9;
        if (dp[currentIndex][remainingWalls] != -1) return dp[currentIndex][remainingWalls];

        int notTake = 0 + minPaintCost(cost, time, currentIndex - 1, remainingWalls, dp);
        int take = cost[currentIndex] + minPaintCost(cost, time, currentIndex - 1, remainingWalls - time[currentIndex] - 1, dp);
        return dp[currentIndex][remainingWalls] = min(notTake, take);
    }

public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return minPaintCost(cost, time, n - 1, n, dp);
    }
}
