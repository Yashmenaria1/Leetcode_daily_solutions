class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = size(nums), max_i = 0;
        vector<int> dp(n, 1), pred(n, -1), ans;
        for(int i = 1; i < n; i++) {          
            for(int j = 0; j < i; j++)
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j]+1)
                    dp[i] = dp[j]+1, pred[i] = j;
            if(dp[i] > dp[max_i]) max_i = i;  
        }
        for(; max_i >= 0; max_i = pred[max_i]) 
            ans.push_back(nums[max_i]);
        return ans;
    }
};
