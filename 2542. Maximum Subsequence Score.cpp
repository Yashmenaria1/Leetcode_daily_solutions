class Solution {
 public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    long long maximumScore = 0;
    long long sum = 0;
    vector<pair<int, int>> pairsOfElements;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (int i = 0; i < nums1.size(); ++i)
      pairsOfElements.emplace_back(nums2[i], nums1[i]);

    sort(begin(pairsOfElements), end(pairsOfElements), greater<>());

    for (const auto& [num2, num1] : pairsOfElements) {
      minHeap.push(num1);
      sum += num1;
      if (minHeap.size() > k)
        sum -= minHeap.top(), minHeap.pop();
      if (minHeap.size() == k)
        maximumScore = max(maximumScore, sum * num2);
    }

    return maximumScore;
  }
}; 
