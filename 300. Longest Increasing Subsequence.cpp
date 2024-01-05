class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            if (ans.empty() || ans[ans.size() - 1] < x) {
                ans.push_back(x);
            } else {
                auto it = lower_bound(ans.begin(), ans.end(), x); 
                *it = x; 
            }
        }
        return ans.size();
    }
};
