class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorRes = 0;
        for(int n : nums) {
            xorRes ^= n;
        }
        long long diffBit = xorRes & ~(xorRes - 1);
        int num1 = 0, num2 = 0;
        for(int n : nums) {
            if(n & diffBit) {
                num1 ^= n;
            } else {
                num2 ^= n;
            }
        }
        return {num1, num2};
    }
};
