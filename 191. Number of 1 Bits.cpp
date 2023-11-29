class Solution {
    public:
        int hammingWeight(uint32_t n) {
        int count = 0;
    
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};


class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ans = 0;

    for (int i = 0; i < 32; ++i)
      if ((n >> i) & 1)
        ++ans;

    return ans;
  }
};
