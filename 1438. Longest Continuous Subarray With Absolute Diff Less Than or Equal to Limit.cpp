class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int left = 0, right = 0, res = 0;
        
        while (right < nums.size()) {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[left++]));
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
