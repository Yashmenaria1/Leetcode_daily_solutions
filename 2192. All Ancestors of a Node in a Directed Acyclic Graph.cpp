class Solution {
public:
    void dfs(vector<vector<int>>& graph, int i, int j, vector<vector<int>>& ans){
        for(auto& g: graph[j]){
            if(ans[g].empty() || ans[g].back()!=i){
                ans[g].push_back(i);
                dfs(graph,i,g,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), graph(n);
        for(auto& e:edges){
            graph[e[0]].push_back(e[1]);
        }
        for(int i = 0; i<n; i++){
            dfs(graph, i, i, ans);
        }
        return ans;
    }
};
