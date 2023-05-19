class Solution {
private:
    int colours[100] = {};
    bool exploreFromNode(vector<vector<int>>& graph, int startNode = 0, bool isGroupA = true) {
        colours[startNode] = isGroupA ? 1 : -1;
        for (int n: graph[startNode]) {
            if (colours[n]) {
                if (colours[n] == (isGroupA ? 1 : -1)) return false;
            }
            else {
                if (!exploreFromNode(graph, n, !isGroupA)) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        for (int i = 0, limit = graph.size(); i < limit; i++) {
            if (!colours[i] && !exploreFromNode(graph, i)) return false;
        }
        return true;
    }
};
