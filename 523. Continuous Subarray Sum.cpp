class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        unordered_map<int, int> remMap;
        remMap[0] = -1; 

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0) rem += k;
            if (remMap.find(rem) != remMap.end()) {
                if (i - remMap[rem] > 1) {
                    return true;
                }
            } else {
                remMap[rem] = i;
            }
        }
        return false;
    }
};
