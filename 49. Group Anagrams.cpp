class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> index;
        vector<vector<string>> res;
        for (string& s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            if (index.find(t) == index.end()) {
                index[t] = res.size();
                res.push_back({});
            }
            res[index[t]].push_back(s);
        }
        return res;
    }
};
