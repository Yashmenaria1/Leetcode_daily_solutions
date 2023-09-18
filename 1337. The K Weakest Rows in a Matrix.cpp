class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        set<pair<int, int>> s;
        for (auto i = 0; i < mat.size(); i++) {
            auto count = accumulate(mat[i].begin(), mat[i].end(), 0);
            s.insert(make_pair(count, i));
        }
        vector<int> res;
        for (auto it = s.begin(); it != s.end(), k > 0; k--, it++)
            res.push_back(it->second);
        return res;
    }
};
