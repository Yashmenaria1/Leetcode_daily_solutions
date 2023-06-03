class Solution {
 public:
  int dfs(int employee, vector<vector<int>>& adjList, vector<int>& informTime) {
    int maxTime = 0;
    for (int subEmployee : adjList[employee]) {
        maxTime = max(maxTime, dfs(subEmployee, adjList, informTime));
        }
    return informTime[employee] + maxTime;
    }
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; i++) {
        if (manager[i] != -1) {
            adjList[manager[i]].push_back(i);
            }
        }
    return dfs(headID, adjList, informTime);
    }
};
