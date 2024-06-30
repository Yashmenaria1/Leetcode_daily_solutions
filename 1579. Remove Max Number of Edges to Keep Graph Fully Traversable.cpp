class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        vector<int> rootA(n + 1);
        vector<int> rootB(n + 1);
        for (int i = 1; i <= n; i++) {
            rootA[i] = i;
            rootB[i] = i;
        }

        int res = 0;
        int alice_Edges = 0;
        int bob_Edges = 0;

        
        for (auto& edge : edges) {
            if (edge[0] == 3) {
                if (uni(edge[1], edge[2], rootA)) {
                    alice_Edges++;
                    if (uni(edge[1], edge[2], rootB)) {
                        bob_Edges++;
                    }
                } else {
                    res++;
                }
            }
        }

        vector<int> rootA_copy = rootA;

        
        for (auto& edge : edges) {
            if (edge[0] == 1) {
                if (uni(edge[1], edge[2], rootA)) {
                    alice_Edges++;
                } else {
                    res++;
                }
            }
        }

        
        rootA = rootA_copy;
        for (auto& edge : edges) {
            if (edge[0] == 2) {
                if (uni(edge[1], edge[2], rootB)) {
                    bob_Edges++;
                } else {
                    res++;
                }
            }
        }

        return (alice_Edges == bob_Edges && alice_Edges == n - 1) ? res : -1;
    }

    bool uni(int a, int b, vector<int>& root) {
        int rootA = find(a, root);
        int rootB = find(b, root);
        if (rootA == rootB) {
            return false;
        }
        root[rootA] = rootB;
        return true;
    }

    int find(int a, vector<int>& root) {
        if (root[a] != a) {
            root[a] = find(root[a], root);
        }
        return root[a];
    }
};
