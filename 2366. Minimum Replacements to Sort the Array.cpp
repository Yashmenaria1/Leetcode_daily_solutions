class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int min = nums[nums.size()-1];

        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] <= min){
                min = nums[i];
                continue;
            }

            int parts;
            if(nums[i] % min == 0){
                parts = nums[i] / min;
            }
            else{
                parts = (nums[i] / min) + 1;
            }

            ans += parts - 1;
            min = nums[i] / parts;
        }

        return ans;
    }
};
