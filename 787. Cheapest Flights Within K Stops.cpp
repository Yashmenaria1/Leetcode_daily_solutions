class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> cost(n, 1e8);
        cost[src] = 0;
        
        for(int i = 0; i <= k; i++){
            vector<int> C(cost);
            for(auto e: flights)
                C[e[1]] = min(C[e[1]], cost[e[0]] + e[2]);
            cost = C;
        }
        return cost[dst] == 1e8 ? -1 : cost[dst];
    }
};
