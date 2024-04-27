class Solution {
public:
    int findSteps(int p1, int p2, string &ring, string &key, vector<vector<int>>& memo, vector<int> pos[26]) {
        if (p2 == key.size()) return 0;
        if (memo[p1][p2] != -1) return memo[p1][p2];

        int r = ring.size(), ms = INT_MAX;
        for (int nxt : pos[key[p2] - 'a']) {
            int dist = abs(p1 - nxt);
            int steps = min(dist, r - dist) + findSteps(nxt, p2 + 1, ring, key, memo, pos);
            ms = min(ms, steps);
        }
        return memo[p1][p2] = ms + 1;
    }

    int findRotateSteps(string ring, string key) {
        vector<int> pos[26];
        for (int i = 0; i < ring.size(); i++) pos[ring[i] - 'a'].push_back(i);
    
        vector<vector<int>> memo(ring.size(), vector<int>(key.size(), -1));
        return findSteps(0, 0, ring, key, memo, pos);
    }
};
