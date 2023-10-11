class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start, end;
        for (auto& t : flowers)
            start.push_back(t[0]), end.push_back(t[1]);
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> ans;
        for (int t : persons) {
            int start_idx = upper_bound(start.begin(), start.end(), t) - start.begin();
            int end_idx = lower_bound(end.begin(), end.end(), t) - end.begin();
            ans.push_back(start_idx - end_idx);
        }
        return ans;
    }
};
