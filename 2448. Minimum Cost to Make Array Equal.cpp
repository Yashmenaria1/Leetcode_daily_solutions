class Solution {
public:
    long long calculateSum(vector<int>& nums, vector<int>& cost, long long target) {
        long long ans = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            ans += abs(nums[i] - target) * cost[i];
        }
        return ans;
    }


    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long start = *min_element(nums.begin(), nums.end());
        long long end = *max_element(nums.begin(), nums.end());
        while (start < end) {
            long long mid = start + (end - start) / 2;
            long long leftSum = calculateSum(nums, cost, mid);
            long long rightSum = calculateSum(nums, cost, mid + 1);
            if (leftSum < rightSum) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return calculateSum(nums, cost, start);
    }
};
