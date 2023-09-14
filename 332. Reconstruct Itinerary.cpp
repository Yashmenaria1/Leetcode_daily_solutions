class Solution {
    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m;
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            m[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void dfs(string src) {
        while (!m[src].empty()) {
            string destination = m[src].top();
            m[src].pop();
            dfs(destination);
        }
        ans.push_back(src);
    }
};
