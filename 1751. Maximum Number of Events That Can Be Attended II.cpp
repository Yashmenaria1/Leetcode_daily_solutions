class Solution {
public:

int Finder(int index,vector<vector<int>>&events,int value)
{
    int start = index;
    int end = events.size()-1;
    int res = -1;
    while(end>=start)
    {
      int mid = start+(end-start)/2;
      if(events[mid][0] > value)
      {
        res = mid;
        end = mid-1;
      }
      else start = mid+1;
    }
    return res;
}

int helper(int i,vector<vector<int>>&events,int k, vector<vector<int>>&dp)
{
  if(i >= events.size() || k == 0 || i == -1) return 0;
  if(dp[i][k] != -1) return dp[i][k];

  int index = Finder(i+1,events,events[i][1]);

  int c1 = events[i][2] + helper(index,events,k-1,dp);
  int c2 = helper(i+1,events,k,dp);

  return dp[i][k] = max(c1,c2);
}


 int maxValue(vector<vector<int>>& events, int k){

    sort(events.begin(),events.end());
    int n = events.size();
    vector<vector<int>>dp(n+5,vector<int>(k+1,-1));
    return helper(0,events,k,dp);
  }
};
