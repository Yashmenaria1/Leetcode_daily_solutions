class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int x = n - i;
            if(nums[i] >= x && (i == 0 || nums[i-1] < x)) {
                return x;
            }
        }
        return -1;
    }
};
