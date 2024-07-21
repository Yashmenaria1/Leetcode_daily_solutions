class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& nums, int n){
        vector<int> order;
        vector<vector<int>> g(n+1);
        vector<int> indegree(n+1);
        queue<int> q;

        for(auto n:nums){
            int u = n[0];
            int v= n[1];
            g[u].push_back(v);
            ++indegree[v];
        }
        for(int i = 1; i<=n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            order.push_back(top);
            for(auto v:g[top]){
                if(--indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return order.size()==n ? order : vector<int>();
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topoSort(rowConditions, k);
        if(rowOrder.empty()) return {};
        vector<int> colOrder = topoSort(colConditions, k);
        if(colOrder.empty()) return {};

        vector<vector<int>> ans(k, vector<int>(k));
        vector<int> v(k+1);
        for(int i = 0; i<k; i++){
            v[rowOrder[i]] = i;
        }
        for(int j = 0; j<k; j++){
            const int node = colOrder[j];
            const int i = v[node];
            ans[i][j] = node;
        }
        return ans;
    }
};
