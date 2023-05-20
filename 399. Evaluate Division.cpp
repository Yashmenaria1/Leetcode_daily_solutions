class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            const double value = values[i];

            graph[A][B] = value;
            graph[B][A] = 1.0 / value;
        }

        vector<double> results;
        for (const vector<string>& query : queries) {
            const string& C = query[0];
            const string& D = query[1];

            if (!graph.count(C) || !graph.count(D)) {
                results.push_back(-1.0);
                continue;
            }

            unordered_map<string, bool> visited;
            double result = dfs(C, D, visited);
            results.push_back(result);
        }

        return results;
    }

    double dfs(const string& curr, const string& target, unordered_map<string, bool>& visited) {
        if (curr == target)
            return 1.0;

        visited[curr] = true;
        for (const auto& neighbor : graph[curr]) {
            const string& next = neighbor.first;
            const double value = neighbor.second;

            if (visited.count(next))
                continue;

            double result = dfs(next, target, visited);
            if (result != -1.0)
                return result * value;
        }

        return -1.0;
    }
};
