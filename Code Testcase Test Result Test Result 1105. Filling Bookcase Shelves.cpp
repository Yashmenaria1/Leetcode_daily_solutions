class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i = 1; i<=n; i++){
            int currWidth = books[i-1][0], currHeight = books[i-1][1];
            dp[i] = dp[i-1] + currHeight;
            for(int j = i-1; j>0; j--){
                currWidth += books[j-1][0];
                if(currWidth > shelfWidth){
                    break;
                }
                currHeight = max(currHeight, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1]+currHeight);
            }
        }
        return dp[n];
    }
};
