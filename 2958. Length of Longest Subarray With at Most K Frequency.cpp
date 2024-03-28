class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int ans = 0, i = 0, n = nums.size();
        for (int j = 0; j < n; ++j) {   
            count[nums[j]]++;
            while (count[nums[j]] > k)
                count[nums[i++]]--;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
