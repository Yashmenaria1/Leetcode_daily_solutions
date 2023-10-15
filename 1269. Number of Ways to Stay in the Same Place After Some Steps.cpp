class Solution {
    int mod = pow(10, 9) + 7;
    vector<int> ways{0, -1, 1};
    vector<vector<int>> dp;
public:
    int numWays(int n, int len) {
        dp.resize(n+1, vector<int>((n)/2 + 1, -1));
        return solve(n, len);
    }
    
    int solve(int n, int len, int pos = 0) {
        if(n == 0 && pos == 0) return 1;
        
        if(pos < 0 || pos >= len || n == 0 || pos > n) return 0;
        
        if(dp[n][pos] != -1) return dp[n][pos];
        
        int ans = 0;
        for(int i=0; i<3; i++) {
            ans = (ans % mod + solve(n-1, len, pos + ways[i]) % mod) % mod;
        }
        
        return dp[n][pos] = ans % mod;
        
    }
};
