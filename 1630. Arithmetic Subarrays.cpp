class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for (auto i = 0; i < l.size(); i++) {
            vector<int> n(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(n.begin(), n.end());
            int j;
            for (j = 2; j < n.size(); j++) {
                if (n[j] - n[j - 1] != n[1] - n[0]) {
                    break;
                }
            }
            res.push_back(j == n.size());
        }
        return res;
    }
};
