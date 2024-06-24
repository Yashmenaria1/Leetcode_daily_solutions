class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> isFlipped(n, 0);
        int flip = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k) flip ^= isFlipped[i - k];
            if (nums[i] == flip) {
                if (i + k > n) return -1;
                flip ^= 1;
                isFlipped[i] = 1;
                result++;
            }
        }
        return result;
    }
};
