class Solution {
public:
    int minDifference(vector<int>& nums) {
        int k = nums.size();
        
        if(k <= 4) return 0;
        sort(nums.begin(), nums.end());

        int res = min(min((nums[k-4] - nums[0]), (nums[k-3] - nums[1])), min((nums[k-2] - nums[2]), (nums[k-1] - nums[3])));
        return res;
    }
};
