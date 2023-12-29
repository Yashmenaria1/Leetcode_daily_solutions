
#define INF 10000000
class Solution {
public:
    int n;
    int dp[305][15];
    int dfs(int i, int d, vector <int> &mat)
    {
        if(i == n && d == 0)
            return 0;
        if(i == n || d == 0 || n - i < d) 
            return INF;
        if(dp[i][d] != -1)
            return dp[i][d];
        int ans = INT_MAX;
        int Max = INT_MIN;
        for(int j = i; j < n; j++)
        {   
            Max = max(Max, mat[j]); 
            ans = min(ans, Max + dfs(j + 1, d - 1, mat));
        }
        dp[i][d] = ans;
        return ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n= jobDifficulty.size();
        if(n < d)     
            return -1;
        memset(dp, -1, sizeof(dp));
        int ans = dfs(0, d, jobDifficulty);
        return ans;
    }
};
