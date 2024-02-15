class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = -1, curr = 0;
        for (int i = 0; i < nums.size(); ++i)
            if ((curr += nums[i]) > nums[i] * 2)
                res = curr;
        return res;
    }
};
