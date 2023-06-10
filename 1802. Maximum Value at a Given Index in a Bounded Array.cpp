class Solution {
 public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;

    int low = 0;
    int high = maxSum;

    while (low < high) {
      const int mid = low + (high - low) / 2;
      if (getSum(n, index, mid) >= maxSum)
        high = mid;
      else
        low = mid + 1;
    }

    return getSum(n, index, low) > maxSum ? low : low + 1;
  }

 private:
  long getSum(int n, int index, int x) {
    long low = min(index, x - 1);
    long high = min(n - index, x);
    long lSum = ((x - 1) + (x - 1 - low + 1)) * low / 2;
    long rSum = (x + (x - high + 1)) * high / 2;
    return lSum + rSum;
  }
};
