class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    int cnt[20001] = {}, res = 0;
    for (int l = 0, m = 0, r = 0; r < nums.size(); ++r) {
        if (++cnt[nums[r]] == 1)
            if (--k < 0) {
                cnt[nums[m++]] = 0;
                l = m;
            }
        if (k <= 0) {
            while (cnt[nums[m]] > 1)
                --cnt[nums[m++]];
            res += m - l + 1;   
        }
    }
    return res;
} 
};
