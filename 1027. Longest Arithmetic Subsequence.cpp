class Solution {
public:
    int dp[1001][1001];
    int longestArithSeqLength(vector<int>& nums) {
        memset(dp , 0 , sizeof(dp));
         int n=nums.size();
         int maxlen =1;
         for(int i=1 ; i<n ;i++)
         {
             for(int j=0;j<i;j++)
             {
                 int diff=nums[i]-nums[j] + 500;
                 
                 dp[i][diff] = max(dp[i][diff] , 1 + dp[j][diff]);
                 
                 maxlen = max(maxlen , dp[i][diff]);
                 
             }
         }
         
         return maxlen + 1;
    }

};
