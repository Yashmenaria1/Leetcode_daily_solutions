class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> out(n);
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(auto nbr: graph[i]){
                out[i]++;
                adj[nbr].push_back(i);
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(out[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int top = q.front(); q.pop();
            ans.push_back(top);
            for(auto nbr: adj[top]){
                out[nbr]--;
                if(out[nbr]==0) q.push(nbr);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
