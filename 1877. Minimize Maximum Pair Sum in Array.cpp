class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = INT_MIN;
        sort(begin(nums), end(nums));

        for(int i = 0; i< nums.size() / 2; i++)
            ans = max(ans, nums[i] + nums[nums.size() - i- 1]);
        return ans;
    }
};
