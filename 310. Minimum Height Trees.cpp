class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<unordered_set<int>> graph(n);
        vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }
        while (n > 2) {
            int num_leaves = leaves.size();
            n -= num_leaves;
            
            for (int i = 0; i < num_leaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : graph[leaf]) {
                    graph[neighbor].erase(leaf);
                    if (--degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};
