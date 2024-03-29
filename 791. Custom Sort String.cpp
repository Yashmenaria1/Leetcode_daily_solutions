class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> dir;
        for (int i = 0; i < order.size(); i++) {
            dir[order[i]] = i + 1;
        }
        sort(s.begin(), s.end(),
             [&](char a, char b) { return dir[a] < dir[b]; });
        return s;
    }
};
