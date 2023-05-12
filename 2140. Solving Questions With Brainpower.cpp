class Solution {
 public:
  long long mostPoints(vector<vector<int>>& questions) {
    const int n = questions.size();
    vector<long long> dp(n + 1);

    for (int i = n - 1; i >= 0; --i) {
      const int points = questions[i][0];
      const int numberofQuestionsSkipped = questions[i][1];
      const int nextQuestion = i + numberofQuestionsSkipped + 1;
      const long long maximumPoints = nextQuestion < n ? dp[nextQuestion] : 0;
      dp[i] = max(points + maximumPoints, dp[i + 1]);
    }

    return dp[0];
  }
};
