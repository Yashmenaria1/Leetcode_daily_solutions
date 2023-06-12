class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;

    for (int i = 0; i < nums.size(); ++i) {
      const int begin = nums[i];
      while (i + 1 < nums.size() && nums[i] == nums[i + 1] - 1)
        ++i;
      const int end = nums[i];
      if (begin == end)
        res.push_back(to_string(begin));
      else
        res.push_back(to_string(begin) + "->" + to_string(end));
    }

    return res;
  }
};
