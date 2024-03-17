class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = newInterval[0], e = newInterval[1];
        vector<vector<int>> left, right;
        for (auto& i : intervals) {
            if (i[1] < s) {
                left.push_back(i);
            } else if (i[0] > e) {
                right.push_back(i);
            } else {
                s = min(s, i[0]);
                e = max(e, i[1]);
            }
        }
        vector<vector<int>> result;
        result.insert(result.end(), left.begin(), left.end());
        result.push_back({s, e});
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }
};
