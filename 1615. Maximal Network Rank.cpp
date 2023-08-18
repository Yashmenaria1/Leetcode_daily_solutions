class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto& edge: roads){
            int v=edge[0], w=edge[1];
            indegree[v]++;
           indegree[w]++;
            adj[v].insert(w);
            adj[w].insert(v);
        }
        int maxdegree=0;
        for(int i=0;i<indegree.size();i++){
          maxdegree=max(maxdegree,indegree[i]);
        }
        vector<int> maxindex; 
        for(int i=0; i<n; i++){
            if(indegree[i]==maxdegree) maxindex.push_back(i);
        }
        int samemaxdegree=maxindex.size();
        if (samemaxdegree>1){
            for (int i=1; i<samemaxdegree; i++){
                for (int j=0; j<i; j++)
                    if (adj[maxindex[i]].count(maxindex[j])==0) {
                       cout<<maxindex[i]<<maxindex[j];
                         return 2*maxdegree;
                    }
                        
            }
            return 2*maxdegree-1;
        }
        int mxid=maxindex[0];
        int max_rank=0;
        for(int j=0; j<n; j++){
            if (j==mxid) continue;
            int rank=maxdegree+indegree[j]-adj[mxid].count(j);
            max_rank=max(max_rank, rank);
            cout<<mxid;
        }
        return max_rank;
    }
};
