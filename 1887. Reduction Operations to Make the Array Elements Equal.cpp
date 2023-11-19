class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i - 1] != nums[i])
                res += nums.size() - i;
        }
        return res;
    }
};
