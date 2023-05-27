class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) 
    {
       int n = stoneValue.size(); 
       vector<int> dp(3, 0); 

       for (int i = n - 1; i >= 0; i--) {
            int takeOnePiles = stoneValue[i] - dp[(i + 1) % 3];

            int takeTwoPiles = INT_MIN;
            if (i + 1 < n) takeTwoPiles = stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 3];

            int takeThreePiles = INT_MIN;
            if (i + 2 < n) takeThreePiles = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 3];

            dp[i % 3] = max({takeOnePiles, takeTwoPiles, takeThreePiles});
        } 

       int score = dp[0]; 
       if(score > 0)
           return "Alice";
        else if(score  < 0)
            return "Bob";
        else
            return "Tie";
    }
};
