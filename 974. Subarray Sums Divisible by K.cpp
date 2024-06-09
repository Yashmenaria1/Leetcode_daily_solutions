class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        int cumSum = 0;
        int count = 0;
        
        for (int num : nums) {
            cumSum += num;
            int rem = cumSum % k;
            if (rem < 0) {
                rem += k;
            }
            if (mp.find(rem) != mp.end()) {
                count += mp[rem];
            }
            mp[rem]++;
        }
        return count;
    }
};
